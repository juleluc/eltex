#include "main.h"



void writer_process(int pipefd[2], char *filename, pid_t child_pid, int sem_id) {
    printf("[Writer %d] Начало работы\n", getpid());
    close(pipefd[1]); 
    int num;

    while (read(pipefd[0], &num, sizeof(num)) > 0) {
        printf("\n[Writer %d] Попытка захватить семафор\n", getpid());
        writer_lock(sem_id);
        printf("[Writer %d] Семафор захвачен\n", getpid());
    
        printf("[Writer %d] Прочитано число из канала: %d\n", getpid(), num);
    
        FILE *file = fopen(FILENAME, "a");
        if (!file) {
            perror("[Writer] Не удалось открыть файл");
            writer_unlock(sem_id);
            exit(EXIT_FAILURE);
        }
    
        fprintf(file, "Parent write to file: %d\n", num);
        fclose(file);
        printf("[Writer %d] Запись завершена\n", getpid());
    
        writer_unlock(sem_id);
        printf("[Writer %d] Семафор освобождён\n", getpid());
    }
    

    close(pipefd[0]);
    waitpid(child_pid, NULL, 0);
    printf("[Writer %d] Работа завершена\n", getpid());
}