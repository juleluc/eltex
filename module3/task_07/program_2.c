#include"msgchat.h"

int main()
{

    
    mqd_t ds = mq_open(MSG_QUEUE_FILE,  O_RDWR, 0644, NULL);
    if (ds == (mqd_t)-1){
        perror("mq_open");
        exit(EXIT_FAILURE);
    }

    char message[MAX_MSG_SIZE];
    unsigned int priority;
    
    while(1){
        
        receive_message(ds, message, sizeof(message), &priority);
        
        if (priority == END_MSG_TYPE){
            printf("Friend Exit\n");
            break;
        }
        
        printf("Friend: %s\n", message);
        
        printf("You: \n");
        input_read(message, sizeof(message));

        
        if (strcmp(message, "exit") == 0) {
            mq_send(ds, message, strlen(message) + 1, END_MSG_TYPE);
            break;
        }

        send_message(ds, message, MSG_TYPE);

    }
    mq_close(ds);
    mq_unlink(MSG_QUEUE_FILE);
    printf("Program 2 finished.\n");
    return 0;

}
