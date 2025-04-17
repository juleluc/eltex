#include "main.h"



void parent_process(int pipefd[2], char *filename, pid_t child_pid){
    printf("Parent: PID - %d\n", getpid());
    close(pipefd[1]); 
    int num;

    while(read(pipefd[0], &num, sizeof(num)) > 0){
        while(!flag_block){
            pause();
        }
        printf("Parent process: %d прочитано число из канала: %d\n", getpid(), num);

        FILE *file = fopen(FILENAME, "a"); 
        if (file == NULL) {
            perror("Parent: Не удалось открыть файл");
            exit(EXIT_FAILURE);
        }

        printf("Запись числа в файл\n\n");
        fprintf(file, "Parent write to file: %d\n", num);
        fclose(file);

        printf("Parent отправляет SIGUSR2 (разрешение доступа к файлу)\n");
        kill(child_pid, SIGUSR2);
    
    }
    close(pipefd[0]);
    waitpid(child_pid, NULL, 0);
}