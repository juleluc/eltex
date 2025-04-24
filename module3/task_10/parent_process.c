#include "main.h"



void parent_process(int pipefd[2], char *filename, pid_t child_pid, sem_t *sem){
    printf("Parent: PID - %d\n", getpid());
    close(pipefd[1]); 
    int num;

    while (read(pipefd[0], &num, sizeof(num)) > 0) {
        printf("\n[Parent %d] Получил число из канала: %d\n", getpid(), num);
        printf("[Parent %d] попытка захватить семафор\n", getpid());
        sem_wait(sem);
        printf("[Parent %d] Семафор захвачен, записываю число: %d\n", getpid(), num);
    
        FILE *file = fopen(FILENAME, "a");
        if (!file) {
            perror("[Parent] Ошибка открытия файла");
            sem_post(sem);
            exit(EXIT_FAILURE);
        }
        printf("[Parent %d] запись в файл\n", getpid());
        fprintf(file, "Parent write to file: %d\n", num);
        fclose(file);
    
        sem_post(sem);
        printf("[Parent %d] Семафор освобождён\n", getpid());
    }
}    