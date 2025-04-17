#include "msgchat.h"


void create_file(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }
    fclose(file);
}

void send_message(int msgid, struct msgbuf *msg){
    if (msgsnd(msgid, msg, strlen(msg->mtext)+1, 0) == -1) {
        perror("msgsnd");
        exit(EXIT_FAILURE);
    }
}


void receive_message(int msgid, struct msgbuf *msg){
    if (msgrcv(msgid, msg, MAX_MSG_SIZE, 0, 0) == -1) {
        perror("msgrcv");
        exit(EXIT_FAILURE);
    }
}


void read_input(char *buff, size_t size){
    fgets(buff, size, stdin);
    buff[strcspn(buff, "\n")] = '\0';
}

int init_queue(){
    key_t key = ftok(MSG_QUEUE_FILE, PROG_ID);
    if (key == -1) {
        perror("ftok");
        exit(EXIT_FAILURE);
    }

    int msgid = msgget(key, 0644 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    return msgid;

}


void remove_queue(int msgid){
    if (msgctl(msgid, IPC_RMID, NULL) == -1) {
        perror("msgctl");
    } else {
        printf("Queue deleted.\n");
    }
}