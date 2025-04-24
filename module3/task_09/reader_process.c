#include "main.h"



void reader_process(int pipefd[2], char *filename, int sem_id) {
    close(pipefd[0]); // Закрываем чтение из канала
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        perror("[Reader] Не удалось открыть файл");
        exit(EXIT_FAILURE);
    }

    int num;
    while (fscanf(file, "%d", &num) == 1) {
        printf("\n[Reader %d] Попытка захватить семафор\n", getpid());
        reader_lock(sem_id);
        printf("[Reader %d] Семафор захвачен\n", getpid());

        printf("[Reader %d] Прочитано число из файла: %d\n", getpid(), num);
        write(pipefd[1], &num, sizeof(num));
        printf("[Reader %d] Число %d записано в канал\n", getpid(), num);

        reader_unlock(sem_id);
        printf("[Reader %d] Семафор освобождён\n", getpid());
    }

    fclose(file);
    close(pipefd[1]);
    printf("[Reader %d] Работа завершена\n", getpid());
    exit(EXIT_SUCCESS);
}
