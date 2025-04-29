#include "common.h"



void create_and_bind_socket(int *sockfd, struct sockaddr_in *server_addr, int port) {
    memset(server_addr, 0, sizeof(*server_addr));

    server_addr->sin_family = AF_INET;
    server_addr->sin_port = htons(port);
    server_addr->sin_addr.s_addr = htonl(INADDR_ANY);

    if ((*sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    if (bind(*sockfd, (struct sockaddr *)server_addr, sizeof(*server_addr)) < 0) {
        perror("bind failed");
        close(*sockfd);
        exit(EXIT_FAILURE);
    }
}


void receive_messages(int sockfd) {
    char recvline[MAX_SIZE];
    int n;

    while (1) {
        n = recvfrom(sockfd, recvline, MAX_SIZE, 0, NULL, NULL);
        if (n < 0) {
            perror("recvfrom failed");
            close(sockfd);
            exit(EXIT_FAILURE);
        }
        recvline[n] = '\0';
        printf("\nReceived: %s\nString => ", recvline);
    }
}


void send_message(int sockfd, struct sockaddr_in *server_addr) {
    char sendline[MAX_SIZE];

    while (1) {
        printf("String => ");
        if (fgets(sendline, MAX_SIZE, stdin) == NULL) {
            printf("\nInput error\n");
            break;
        }

        sendline[strcspn(sendline, "\n")] = '\0'; 

        if (strcmp(sendline, "exit") == 0) {
            printf("Exiting\n");
            close(sockfd);
            exit(EXIT_SUCCESS);
        }

        if (sendto(sockfd, sendline, strlen(sendline) + 1, 0, (struct sockaddr *)server_addr, sizeof(*server_addr)) < 0) {
            perror("sendto failed");
            close(sockfd);
            exit(EXIT_FAILURE);
        }
    }
}

void register_client(struct sockaddr_in *client_addr, struct sockaddr_in *client_addr1, struct sockaddr_in *client_addr2, int *know_client1, int *know_client2) {
    if (!(*know_client1)) {
        *client_addr1 = *client_addr;
        *know_client1 = 1;
        printf("Добавлен 1 клиент\n");
    } else if (!(*know_client2) && memcmp(client_addr, client_addr1, sizeof(*client_addr)) != 0) {
        *client_addr2 = *client_addr;
        *know_client2 = 1;
        printf("Добавлен 2 клиент\n");
    }
}

