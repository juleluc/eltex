#include "main.h"


void parse_str(char *input, char **args){
    int count = 0;
    char *sep = strtok(input, " ");

    while (sep != NULL) {
      args[count++] = sep;
      sep = strtok(NULL, " ");
    }
    args[count] = NULL;
}


int main(){

    char input[MAX_LENGTH_STR];
    char *args[MAX_ARGS];

    while(1){
        printf(">> ");
        fgets(input, MAX_LENGTH_STR, stdin);

        input[strcspn(input, "\n")] = '\0';
        parse_str(input, args);

        if (input[0] == '\0') {
            continue;
        }

        if (strcmp(args[0], "exit") == 0) {
            printf("Программа завершена\n");
            break;
        }

        pid_t pid;
        int rv;

        switch (pid = fork()) {
            case -1: {
                perror("fork");
                exit(EXIT_FAILURE);
            }
            case 0: { 
                printf("Child: PID - %d\n", getpid());
                execv(args[0], args);
                exit(EXIT_SUCCESS);
            }
            default: { 
                printf("Parent: PID - %d\n", getpid());
                wait(&rv); 
                printf("PARENT: RETURN STATUS FOR CHILD- %d\n", WEXITSTATUS(rv));
            }
        }

    }


    return 0;
}