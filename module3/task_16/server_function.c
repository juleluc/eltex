#include "server.h"

int create_directory(const char *dir_name) {
    if (access(dir_name, F_OK) == -1) {
        if (mkdir(dir_name, 0777) != 0){
            perror("mkdir");
            return -1; 
        } else {
            printf("Directory '%s' created successfully\n", dir_name);
        }
    } else {
        printf("Directory '%s' already exists\n", dir_name);
    }

    return 0; 
}

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void printusers() {
    if (nclients)
        printf("%d user(s) online\n", nclients);
    else
        printf("No users online\n");
}

void sigchld_handler(int signo) {
    (void)signo;
    while (waitpid(-1, NULL, WNOHANG) > 0)
        nclients--;
}

int receive_file(int sock, const char *filename, long filesize) {
    char buff[FILE_BUFFER_SIZE];
    int bytes_recv;
    long received = 0;

    char filepath[512];
    snprintf(filepath, sizeof(filepath), "received/%s", filename);

    FILE *file = fopen(filepath, "wb");
    if (!file)
    {
        perror("fopen");
        return -1;
    }

    while (received < filesize)
    {
        bytes_recv = read(sock, buff, sizeof(buff));
        if (bytes_recv <= 0)
        {
            fclose(file);
            return -1;
        }
        fwrite(buff, 1, bytes_recv, file);
        received += bytes_recv;
    }

    fclose(file);
    write(sock, "File received successfully\n", 27);
    return 0;
}

void process_sendfile(int sock, const char *buff) {
    char filename[256];
    sscanf(buff + 8, "%s", filename);

    write(sock, "OK", 2);

    char size_buff[1024];
    int bytes_recv = read(sock, size_buff, sizeof(size_buff) - 1);
    if (bytes_recv <= 0)
        return;

    size_buff[bytes_recv] = '\0';
    long filesize = atol(size_buff);

    write(sock, "OK", 2);

    receive_file(sock, filename, filesize);
}

void process_math(int sock) {
    int a, b;
    char operation;
    char buff[1024];

    write(sock, "Enter first number\n", 19);
    if ((read(sock, buff, sizeof(buff) - 1)) <= 0) return;
    buff[strlen(buff)] = '\0';
    a = atoi(buff);

    write(sock, "Enter second number\n", 20);
    if ((read(sock, buff, sizeof(buff) - 1)) <= 0) return;
    buff[strlen(buff)] = '\0';
    b = atoi(buff);

    write(sock, "Enter operation (+, -, *, /)\n", 29);
    if ((read(sock, buff, sizeof(buff) - 1)) <= 0) return;
    buff[strlen(buff)] = '\0';
    operation = buff[0];

    int result = 0;
    switch (operation)
    {
        case '+': result = a + b; break;
        case '-': result = a - b; break;
        case '*': result = a * b; break;
        case '/':
            if (b == 0)
            {
                write(sock, "Error: Division by zero\n", 24);
                return;
            }
            result = a / b;
            break;
        default:
            write(sock, "Invalid operation\n", 18);
            return;
    }

    snprintf(buff, sizeof(buff), "Result: %d\n", result);
    write(sock, buff, strlen(buff));
}

void dostuff(int sock) {
    char buff[1024];
    int bytes_recv;

    while ((bytes_recv = read(sock, buff, sizeof(buff) - 1)) > 0)
    {
        buff[bytes_recv] = '\0';

        if (strncmp(buff, "sendfile", 8) == 0)
        {
            process_sendfile(sock, buff);
        }
        else
        {
            process_math(sock);
        }
    }

    printf("-disconnect\n");
    printusers();
}