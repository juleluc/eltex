#ifndef SERVER_H
#define SERVER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <sys/select.h>

#define MAX_CLIENTS FD_SETSIZE
#define BUF_SIZE    1024

typedef enum {
    STATE_A,
    STATE_B,
    STATE_OPTION
} ClientState;

typedef struct {
    int sockfd;
    ClientState state;
    int a;
    int b;
} ClientInfo;

void error(const char *msg);
void remove_client(ClientInfo clients[], int i, fd_set *all_fds);
int  create_server_socket(int portno);
void handle_new_connection(int listen_sock, ClientInfo clients[], fd_set *all_fds, int *max_fd, struct sockaddr_in cli_addr);
void handle_client_data(int i, ClientInfo clients[], fd_set *all_fds, char buffer[BUF_SIZE]);


#endif