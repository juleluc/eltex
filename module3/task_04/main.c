#include "main.h"


int main(int argc, char *argv[]){

    if (argc != 2){
        fprintf(stderr, "Введите: %s value \n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int number = atoi(argv[1]);
    pid_t pid;
    int rv;
    int pipefd[2];
    if (pipe(pipefd) == -1){
        perror("Create pipe\n");
        exit(EXIT_FAILURE);
    }


    switch (pid = fork())
    {
    case -1:
        perror("fork\n");
        exit(EXIT_FAILURE);
    case 0:
    close(pipefd[0]); 
        printf("Child: PID - %d\n", getpid());
        srand(time(NULL));
        for (int i = 0; i < number; i++){
            int value = rand() % 1000;
            printf("Child send: %d\n", value);
            write(pipefd[1], &value, sizeof(value));
        }
        close(pipefd[1]);
        exit(EXIT_SUCCESS);
    default:
    close(pipefd[1]); 
        printf("Parent: PID - %d\n", getpid());
        int fd = open(FILENAME, O_WRONLY | O_CREAT, 0666);
        if (fd == -1){
            perror("Не удалось открыть файл\n");
            exit(EXIT_FAILURE);
        }
        int random_num;
        for (int i = 0; i < number; i++){
            read(pipefd[0], &random_num, sizeof(random_num));
            printf("Parent получил: %d\n", random_num);
            write(fd, &random_num, sizeof(random_num));
        }

        close(pipefd[0]);
        close(fd);
        wait(&rv);
        printf("PARENT: RETURN STATUS FOR CHILD- %d\n", WEXITSTATUS(rv));
    }


    exit(EXIT_SUCCESS);
}