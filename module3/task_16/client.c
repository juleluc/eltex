#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    int my_sock, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buff[1024];

    if (argc < 3)
    {
        fprintf(stderr, "usage %s hostname port\n", argv[0]);
        exit(0);
    }

    printf("TCP DEMO CLIENT\n");

    portno = atoi(argv[2]);

    my_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (my_sock < 0)
        error("ERROR opening socket");

    server = gethostbyname(argv[1]);
    if (server == NULL)
    {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr_list[0], (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(my_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR connecting");

    printf("Введите 'sendfile <filename>' для отправки файла или enter для операций над числами.\n");

    while (1) {
        printf("S<=C: ");
        if (fgets(buff, sizeof(buff), stdin) == NULL)
            break;

        if (strncmp(buff, "sendfile", 8) == 0) {
            char filename[256];
            sscanf(buff + 8, "%s", filename);

            send(my_sock, buff, strlen(buff), 0);

            if ((n = recv(my_sock, buff, sizeof(buff), 0)) <= 0)
                break;

            FILE *file = fopen(filename, "rb");
            if (!file)
            {
                perror("fopen");
                continue;
            }

            fseek(file, 0L, SEEK_END);
            long filesize = ftell(file);
            rewind(file);

            snprintf(buff, sizeof(buff), "%ld", filesize);
            send(my_sock, buff, strlen(buff), 0);

            if ((n = recv(my_sock, buff, sizeof(buff), 0)) <= 0)
                break;

            size_t nread;
            while ((nread = fread(buff, 1, sizeof(buff), file)) > 0)
            {
                if (send(my_sock, buff, nread, 0) < 0)
                    break;
            }

            fclose(file);

            if ((n = recv(my_sock, buff, sizeof(buff), 0)) > 0)
            {
                buff[n] = '\0';
                printf("Server: %s", buff);
            }
        }
        else
        {
            send(my_sock, buff, strlen(buff), 0);

            if ((n = recv(my_sock, buff, sizeof(buff), 0)) > 0)
            {
                buff[n] = '\0';
                printf("S=>C: %s", buff);
            }
            else
            {
                printf("Server closed connection.\n");
                break;
            }
        }
    }

    close(my_sock);
    return 0;
}