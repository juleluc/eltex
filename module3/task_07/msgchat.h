#ifndef MSGCHAT_H
#define MSGCHAT_H

#include <mqueue.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MSG_TYPE 1
#define END_MSG_TYPE 2
#define MSG_QUEUE_FILE "/msg_queue"
#define MAX_MESSAGES 10
#define MAX_MSG_SIZE 256

mode_t create_queue(struct mq_attr queue_attr);
void input_read(char *message, size_t size);
void send_message(mqd_t ds, char *message, unsigned int priority);
void receive_message(mqd_t ds, char *message, size_t size, unsigned int *priority);

#endif