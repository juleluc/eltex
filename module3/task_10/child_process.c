#include "main.h"



void child_process(int pipefd[2], char *filename, sem_t *sem){
    close(pipefd[0]); 
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        perror("Child: Не удалось открыть файл");
        exit(EXIT_FAILURE);
    }

    int num;
    while (fscanf(file, "%d", &num) == 1) {
        printf("\n[Child %d] попытка захватить семафор\n", getpid());
        sem_wait(sem);
        printf("[Child %d] Семафор захвачен, читаю число: %d\n", getpid(), num);
        
        printf("[Child %d] Записываю число в канал: %d\n", getpid(), num);
        write(pipefd[1], &num, sizeof(num));
        sem_post(sem);
        printf("[Child %d] Семафор освобождён\n", getpid());
    }
    
    fclose(file);
    close(pipefd[1]);
    exit(EXIT_SUCCESS);
}