#include "common.h"

int main() {
    int sockfd;
    char buffer[MAX_SIZE];
    socklen_t clilen;
    int n;
    struct sockaddr_in server_addr, client_addr1, client_addr2, client_addr;
    int know_client1 = 0, know_client2 = 0;

    create_and_bind_socket(&sockfd, &server_addr, PORT);


    printf("Server started on port %d\n", PORT);

    while (1) {
        clilen = sizeof(client_addr);

        if ((n = recvfrom(sockfd, buffer, MAX_SIZE - 1, 0, (struct sockaddr *)&client_addr, &clilen)) < 0) {
            perror("recvfrom failed");
            close(sockfd);
            exit(EXIT_FAILURE);
        }
        buffer[n] = '\0'; 

        register_client(&client_addr, &client_addr1, &client_addr2, &know_client1, &know_client2);

        struct sockaddr_in *dest = NULL;
        if (memcmp(&client_addr, &client_addr1, sizeof(client_addr)) == 0 && know_client2) {
            dest = &client_addr2;
        } else if (memcmp(&client_addr, &client_addr2, sizeof(client_addr)) == 0 && know_client1) {
            dest = &client_addr1;
        }

        if (dest != NULL) {
            if (sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr *)dest, sizeof(*dest)) < 0) {
                perror("sendto failed");
                close(sockfd);
                exit(EXIT_FAILURE);
            }
        }
    }

    close(sockfd);
    return 0;
}
