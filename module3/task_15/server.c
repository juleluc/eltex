#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <signal.h>
#include <sys/wait.h>

// Функция обработки ошибок
void error(const char *msg)
{
    perror(msg);
    exit(1);
}

// Функция обработки данных клиента
void dostuff(int sock);

// Глобальная переменная - количество клиентов
int nclients = 0;

// Печать количества активных пользователей
void printusers()
{
    if (nclients)
        printf("%d user(s) online\n", nclients);
    else
        printf("No users online\n");
}

// Обработчик сигналов для удаления зомби-процессов
void sigchld_handler(int signo)
{
    (void)signo; // Игнорируем параметр
    while (waitpid(-1, NULL, WNOHANG) > 0)
        nclients--;
}

int main(int argc, char *argv[])
{
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *hst;

    if (argc < 2)
    {
        fprintf(stderr, "ERROR, no port provided\n");
        exit(1);
    }

    printf("TCP SERVER DEMO\n");

    // Установка обработчика SIGCHLD
    signal(SIGCHLD, sigchld_handler);

    // Шаг 1 - создание сокета
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    // Шаг 2 - связывание сокета
    memset(&serv_addr, 0, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR on binding");

    // Шаг 3 - ожидание подключений
    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    // Шаг 4 - цикл ожидания клиентов
    while (1)
    {
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
        if (newsockfd < 0)
            error("ERROR on accept");

        nclients++;

        hst = gethostbyaddr((char *)&cli_addr.sin_addr, sizeof(cli_addr.sin_addr), AF_INET);
        printf("+%s [%s] connected!\n", (hst) ? hst->h_name : "Unknown host", inet_ntoa(cli_addr.sin_addr));
        printusers();

        int pid = fork();
        if (pid < 0)
            error("ERROR on fork");

        if (pid == 0) // В дочернем процессе
        {
            close(sockfd);
            dostuff(newsockfd);
            exit(0);
        }
        else
        {
            close(newsockfd); // Родитель закрывает дескриптор клиента
        }
    }

    close(sockfd);
    return 0;
}

void dostuff(int sock)
{
    int bytes_recv;
    int a, b;
    char buff[1024];
    char operation;
    const char *msg1 = "Enter 1 parameter\r\n";
    const char *msg2 = "Enter 2 parameter\r\n";
    const char *msg3 = "Enter operation (+. -, *, /)\n";


    // Отправляем клиенту сообщение
    if (write(sock, msg1, strlen(msg1)) < 0)
        error("ERROR writing to socket");

    // Чтение первого параметра
    bytes_recv = read(sock, buff, sizeof(buff) - 1);
    if (bytes_recv <= 0)
        error("ERROR reading first parameter");
    buff[bytes_recv] = '\0';
    a = atoi(buff);

    // Отправляем клиенту сообщение
    if (write(sock, msg2, strlen(msg2)) < 0)
        error("ERROR writing to socket");

    // Чтение второго параметра
    bytes_recv = read(sock, buff, sizeof(buff) - 1);
    if (bytes_recv <= 0)
        error("ERROR reading second parameter");
    buff[bytes_recv] = '\0';
    b = atoi(buff);

    if (write(sock, msg3, strlen(msg3)) < 0)
    error("ERROR writing to socket");
    // Чтение операции 
    bytes_recv = read(sock, buff, sizeof(buff) - 1);
    if (bytes_recv <= 0)
        error("ERROR reading operation");
    buff[bytes_recv] = '\0';
    operation = buff[0];

    // Вычисление суммы
    int result = 0;
    switch (operation)
    {
    case '+':
        result = a + b;
        break;
    case '-':
        result = a - b;
        break;
    case '*':
        result = a * b;
        break;
    case '/':
        if (b == 0){
            snprintf(buff, sizeof(buff), "Error: Division by zero\n");
            write(sock, buff, strlen(buff));
            printf("-disconnect\n");
            printusers();
            return;
        }
        result = a / b;
        break;
    default:
        snprintf(buff, sizeof(buff), "Error: Invalid operation\n");
        write(sock, buff, strlen(buff));
        printf("-disconnect\n");
        printusers();
        return;
    }
    snprintf(buff, sizeof(buff), "%d\n", result);

    // Отправка результата клиенту
    if (write(sock, buff, strlen(buff)) < 0)
        error("ERROR writing result");

    printf("-disconnect\n");
    printusers();
}
