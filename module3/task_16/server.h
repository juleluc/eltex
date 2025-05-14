#ifndef SERVER_H
#define SERVER_H

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
#include <fcntl.h>
#include <sys/stat.h>
#define FILE_BUFFER_SIZE 1024
extern int nclients;

void dostuff(int sock);
void process_math(int sock);
void process_sendfile(int sock, const char *buff);
int receive_file(int sock, const char *filename, long filesize);
void sigchld_handler(int signo);
void printusers();
void error(const char *msg);
int create_directory(const char *dir_name);

#endif