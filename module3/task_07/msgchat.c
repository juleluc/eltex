#include "msgchat.h"

void create_file(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }
    fclose(file);
}

mode_t create_queue(struct mq_attr queue_attr){
    mqd_t ds = mq_open(MSG_QUEUE_FILE, O_CREAT | O_RDWR, 0644, &queue_attr);
    if (ds == (mqd_t)-1)
    {
        perror("mq_open");
        return (mqd_t)-1;
    }
    return ds;
}

void input_read(char *message, size_t size){
    if(fgets(message, size, stdin) == NULL){
        perror("fgets");
        exit(EXIT_FAILURE);
    }
    message[strcspn(message, "\n")] = '\0';
}

void send_message(mqd_t ds, char *message, unsigned int priority){
    if (mq_send(ds, message, strlen(message) + 1, priority) == -1){
        perror("ms_send");
        exit(EXIT_FAILURE);
    }
}

void receive_message(mqd_t ds, char *message, size_t size, unsigned int *priority){
    if (mq_receive(ds, message, size, priority) == -1){
        perror("mq_receive");
        exit(EXIT_FAILURE);
    }
}