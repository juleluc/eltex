#include "main.h"



void child_process(int pipefd[2], char *filename, int sem_id){
    close(pipefd[0]); 
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        perror("[Child] Не удалось открыть файл");
        exit(EXIT_FAILURE);
    }

    int num;
    while(fscanf(file, "%d", &num) == 1){
        printf("\n[Child %d] попытка захватить семафор\n", getpid());
        lock_semaphore(sem_id);
        printf("[Child %d] Семафор захвачен\n", getpid());

        printf("[Child %d] Прочитано число из файла: %d\n", getpid(), num);
        write(pipefd[1], &num, sizeof(num));
        printf("[Child %d] Число %d записано в канал\n", getpid(), num);

        unlock_semaphore(sem_id);
        printf("[Child %d] Семафор освобождён\n", getpid());

    }
    fclose(file);
    close(pipefd[1]);
    printf("[Child %d] Работа завершена\n", getpid());
    exit(EXIT_SUCCESS);
}
