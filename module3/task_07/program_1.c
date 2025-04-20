#include "msgchat.h"

int main() {
    struct mq_attr queue_attr;
    queue_attr.mq_flags = 0;
    queue_attr.mq_maxmsg = MAX_MESSAGES;
    queue_attr.mq_msgsize = MAX_MSG_SIZE;
    queue_attr.mq_curmsgs = 0;
    
    mqd_t ds = create_queue(queue_attr);
    if (ds == (mqd_t)-1){
        exit(EXIT_FAILURE);
    }

    char message[MAX_MSG_SIZE];
    unsigned int priority = MSG_TYPE;

    while(1){
        printf("You: \n");
        input_read(message, sizeof(message));

        if (strcmp(message, "exit") == 0) {
            send_message(ds, message, END_MSG_TYPE);
            break;
        }

        send_message(ds, message, priority);

        receive_message(ds, message, sizeof(message), &priority);

        if (priority == END_MSG_TYPE){
            printf("Friend Exit\n");
            break;
        }

        printf("Friend: %s\n", message);

    }
    mq_close(ds);
    mq_unlink(MSG_QUEUE_FILE);
    printf("Program 1 finished.\n");
    return 0;

}
