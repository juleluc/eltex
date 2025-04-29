#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#define MAX_SIZE 1024
#define PORT 12345

void send_message(int sockfd, struct sockaddr_in *server_addr);
void receive_messages(int sockfd);
void create_and_bind_socket(int *sockfd, struct sockaddr_in *server_addr, int port);
void register_client(struct sockaddr_in *client_addr, struct sockaddr_in *client_addr1, struct sockaddr_in *client_addr2, int *know_client1, int *know_client2);


#endif