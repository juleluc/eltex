#ifndef MSGCHAT_H
#define MSGCHAT_H

#include <stdio.h>
#include <sys/msg.h>
#include <string.h>
#include <stdlib.h>

#define MAX_MSG_SIZE 100
#define MSG_TYPE 1
#define END_MSG_TYPE 2
#define MSG_QUEUE_FILE "msg_queue"
#define PROG_ID 'A'

struct msgbuf {
    long mtype;
    char mtext[MAX_MSG_SIZE];
};

void create_file(const char *filename);
void send_message(int msgid, struct msgbuf *msg);
void receive_message(int msgid, struct msgbuf *msg);
void read_input(char *buff, size_t size);
int init_queue();
void remove_queue(int msgid);
#endif