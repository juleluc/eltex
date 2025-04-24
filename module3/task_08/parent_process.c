#include "main.h"



void parent_process(int pipefd[2], char *filename, pid_t child_pid, int sem_id){
    printf("Parent: PID - %d\n", getpid());
    close(pipefd[1]); 
    int num;

    while(read(pipefd[0], &num, sizeof(num)) > 0){
        printf("\n[Parent %d] попытка захватить семафор\n", getpid());
        lock_semaphore(sem_id);
        printf("[Parent %d] Семафор захвачен\n", getpid());

        printf("[Parent %d] Прочитано число из канала: %d\n", getpid(), num);

        FILE *file = fopen(FILENAME, "a"); 
        if (file == NULL) {
            perror("[Parent] Не удалось открыть файл");
            unlock_semaphore(sem_id);
            exit(EXIT_FAILURE);
        }
        
        printf("[Parent %d] Запись числа в файл\n", getpid());
        fprintf(file, "Parent write to file: %d\n", num);
        fclose(file);
        printf("[Parent %d] Запись завершена\n", getpid());

        unlock_semaphore(sem_id);
        printf("[Parent %d] Семафор освобождён\n", getpid());
    }
    close(pipefd[0]);
    waitpid(child_pid, NULL, 0);
    printf("[Parent %d] Работа завершена\n", getpid());
}
