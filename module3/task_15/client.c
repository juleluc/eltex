#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

// Функция обработки ошибок
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

    // Шаг 1 - создание сокета
    my_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (my_sock < 0)
        error("ERROR opening socket");

    // Извлечение хоста
    server = gethostbyname(argv[1]);
    if (server == NULL)
    {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    // Заполнение структуры адреса
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr_list[0], (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    // Шаг 2 - подключение к серверу
    if (connect(my_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR connecting");

    // Шаг 3 - передача данных
    while ((n = recv(my_sock, buff, sizeof(buff) - 1, 0)) > 0)
    {
        buff[n] = '\0';
        printf("S=>C: %s", buff);

        printf("S<=C: ");
        if (fgets(buff, sizeof(buff), stdin) == NULL)
            break; // пользователь нажал Ctrl+D или ошибку

        if (strcmp(buff, "quit\n") == 0)
        {
            printf("Exit...\n");
            close(my_sock);
            return 0;
        }

        if (send(my_sock, buff, strlen(buff), 0) < 0)
            error("ERROR sending message");
    }

    if (n < 0)
        error("ERROR receiving data");

    printf("Server closed connection\n");
    close(my_sock);
    return 0;
}
