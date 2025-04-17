#include "main.h"



void child_process(int pipefd[2], char *filename){
    close(pipefd[0]); 
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        perror("Child: Не удалось открыть файл");
        exit(EXIT_FAILURE);
    }

    int num;
    while(fscanf(file, "%d", &num) == 1){
        printf("Child process: %d прочитано число из файла: %d\n", getpid(), num);
        write(pipefd[1], &num, sizeof(num));
        kill(getppid(), SIGUSR1);
        pause(); 
    }
    fclose(file);
    close(pipefd[1]);
    exit(EXIT_SUCCESS);
}