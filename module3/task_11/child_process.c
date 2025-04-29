#include "main.h"



void reader_process(int pipefd[2], char *filename, sem_t *readers_count, sem_t *writers_lock, sem_t *readers_lock){
    close(pipefd[0]); 
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        perror("Child: Не удалось открыть файл");
        exit(EXIT_FAILURE);
    }

    int num;
    while (fscanf(file, "%d", &num) == 1) {
        printf("\n[Child %d] попытка захватить семафор\n", getpid());
        sem_wait(readers_lock);

        int rds_count;
        sem_getvalue(readers_count, &rds_count);
        sem_post(readers_count);

        if (rds_count == 0){
            sem_wait(writers_lock);
        }

        sem_post(readers_lock);
        // printf("[Child %d] Семафор захвачен, читаю число: %d\n", getpid(), num);
        
        printf("[Child %d] Записываю число в канал: %d\n", getpid(), num);
        write(pipefd[1], &num, sizeof(num));
        sem_wait(readers_lock);
        sem_wait(readers_count);
        sem_getvalue(readers_count, &rds_count);

        if (rds_count == 0){
            sem_post(writers_lock);
        }
        sem_post(readers_lock);
        printf("[Child %d] Семафор освобождён\n", getpid());
    }
    
    fclose(file);
    close(pipefd[1]);
    exit(EXIT_SUCCESS);
}