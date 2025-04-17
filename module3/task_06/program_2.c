#include "msgchat.h"

int main() {
    
    int msgid = init_queue();
    struct msgbuf msg;

    while (1) {
        receive_message(msgid, &msg);
        printf("Friend: %s\n", msg.mtext);

        if (msg.mtype == END_MSG_TYPE || strcmp(msg.mtext, "exit") == 0) {
            printf("Friend has exited.\n");
            break;
        }

        printf("You: ");
        read_input(msg.mtext, MAX_MSG_SIZE);
        msg.mtype = MSG_TYPE;

        send_message(msgid, &msg);

        if (strcmp(msg.mtext, "exit") == 0) {
            msg.mtype = END_MSG_TYPE;
            msgsnd(msgid, &msg, strlen(msg.mtext)+1, 0);
            break;
        }
    }

    printf("Program 2 finished.\n");
    return 0;
}
