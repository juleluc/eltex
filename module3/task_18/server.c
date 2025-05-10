#include "server.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    int listen_sock = create_server_socket(atoi(argv[1]));

    struct sockaddr_in cli_addr;
    socklen_t clilen = sizeof(cli_addr);

    ClientInfo clients[MAX_CLIENTS];
    for (int i = 0; i < MAX_CLIENTS; i++) {
        clients[i].sockfd = -1;
    }

    fd_set read_fds, all_fds;
    int max_fd = listen_sock;
    FD_ZERO(&all_fds);
    FD_SET(listen_sock, &all_fds);

    printf("server started on port %d\n", atoi(argv[1]));

    while (1) {
        read_fds = all_fds;

        if (select(max_fd + 1, &read_fds, NULL, NULL, NULL) < 0) {
            if (errno == EINTR) continue;
            error("select() error");
        }

        if (FD_ISSET(listen_sock, &read_fds)) {
            handle_new_connection(listen_sock, clients, &all_fds, &max_fd, cli_addr);
        }

        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i].sockfd != -1 && FD_ISSET(clients[i].sockfd, &read_fds)) {
                char buffer[BUF_SIZE];
                handle_client_data(i, clients, &all_fds, buffer);
            }
        }
    }

    close(listen_sock);
    return 0;
}


int create_server_socket(int portno) {
    int listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock < 0)
        error("ERROR opening socket");

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(listen_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR on binding");

    listen(listen_sock, 5);

    return listen_sock;
}


void handle_new_connection(int listen_sock, ClientInfo clients[], fd_set *all_fds, int *max_fd, struct sockaddr_in cli_addr) {
    socklen_t clilen = sizeof(cli_addr);
    int new_sock = accept(listen_sock, (struct sockaddr *)&cli_addr, &clilen);
    if (new_sock < 0)
        error("accept() error");

    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i].sockfd == -1) {
            clients[i].sockfd = new_sock;
            clients[i].state = STATE_A;
            FD_SET(new_sock, all_fds);
            if (new_sock > *max_fd) {
                *max_fd = new_sock;
            }

            printf("New client connected: %s:%d (slot %d)\n",
                   inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port), i);
            send(new_sock, "Enter 1 parameter:\n", 19, 0);
            return;
        }
    }

    close(new_sock);
}

void handle_client_data(int i, ClientInfo clients[], fd_set *all_fds, char buffer[BUF_SIZE]) {
    int sock = clients[i].sockfd;
    memset(buffer, 0, BUF_SIZE);
    int n = recv(sock, buffer, BUF_SIZE - 1, 0);

    if (n <= 0) {
        remove_client(clients, i, all_fds);
        return;
    }


    if (strcmp(buffer, "exit") == 0) {
        send(sock, "EXIT!\n", 9, 0);
        remove_client(clients, i, all_fds);
        return;
    }

    switch (clients[i].state) {
        case STATE_A:
            clients[i].a = atoi(buffer);
            clients[i].state = STATE_B;
            send(sock, "Enter 2 parameter:\n", 19, 0);
            break;

        case STATE_B:
            clients[i].b = atoi(buffer);
            clients[i].state = STATE_OPTION;
            send(sock, "Enter operation (+, -, *, /):\n", 31, 0);
            break;

        case STATE_OPTION: {
            int result;
            char op = buffer[0];
            int flag = 1;

            if (op == '+')
                result = clients[i].a + clients[i].b;
            else if (op == '-')
                result = clients[i].a - clients[i].b;
            else if (op == '*')
                result = clients[i].a * clients[i].b;
            else if (op == '/') {
                if (clients[i].b == 0) {
                    send(sock, "Error: Division by zero\n", 25, 0);
                    flag = 0;
                } else
                    result = clients[i].a / clients[i].b;
            } else {
                send(sock, "Error: Inflag operation\n", 25, 0);
                flag = 0;
            }

            if (flag) {
                snprintf(buffer, BUF_SIZE, "Result: %d\n", result);
                send(sock, buffer, strlen(buffer), 0);
            }

            clients[i].state = STATE_A;
            send(sock, "Enter 1 parameter:\n", 19, 0);
            break;
        }
    }
}

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void remove_client(ClientInfo clients[], int i, fd_set *all_fds) {
    close(clients[i].sockfd);              
    FD_CLR(clients[i].sockfd, all_fds);    
    clients[i].sockfd = -1;                
    printf("Client %d disconnected\n", i); 
}