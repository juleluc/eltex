#include "common.h"




int main(int argc, char *argv[]){

    int sockfd;
    struct sockaddr_in server_addr, client_addr;
    char sendline[MAX_SIZE], recvline[MAX_SIZE];
    int n, len;

    if (argc != 2){
        printf("Usage: %s <IP address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    create_and_bind_socket(&sockfd, &client_addr, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    if (inet_aton(argv[1], &server_addr.sin_addr) == 0){
        printf("Invalid IP address\n");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("Connected to server at port %d\n", PORT);

    pid_t pid = fork();
    if (pid < 0) {
        perror("fork failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    else if (pid == 0) {
        receive_messages(sockfd);
    } else {
        send_message(sockfd, &server_addr);
    }

    close(sockfd);
    return 0;
}
