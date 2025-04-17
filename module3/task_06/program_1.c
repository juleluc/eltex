#include "msgchat.h"


int main() {

    create_file(MSG_QUEUE_FILE);
    int msgid = init_queue();
    struct msgbuf msg;

    while (1) {
        printf("You: ");
        read_input(msg.mtext, MAX_MSG_SIZE);
        msg.mtype = MSG_TYPE;

        send_message(msgid, &msg);

        if (strcmp(msg.mtext, "exit") == 0) {
            msg.mtype = END_MSG_TYPE;
            msgsnd(msgid, &msg, strlen(msg.mtext)+1, 0);
            break;
        }

        receive_message(msgid, &msg);

        printf("Friend: %s\n", msg.mtext);

        if (strcmp(msg.mtext, "exit") == 0) {
            printf("Friend exited.\n");
            break;
        }
    }

    remove_queue(msgid);
    printf("Program 1 finished.\n");
    return 0;
}
