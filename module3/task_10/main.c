#include "main.h"


int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Введите: %s value\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int number = atoi(argv[1]);
    pid_t pid;
    int rv;
    int pipefd[2];

    if (pipe(pipefd) == -1) {
        perror("Create pipe");
        exit(EXIT_FAILURE);
    }
    srand(time(NULL));

    generate_numbers(FILENAME, number);
    sem_t *sem = sem_open("/numbers", O_CREAT, 0666, 1);
    if (sem == SEM_FAILED) {
        perror("sem_open");
        exit(EXIT_FAILURE);
    }
    switch (pid = fork()) {
        case -1:
            perror("fork");
            exit(EXIT_FAILURE);

        case 0: { 
            child_process(pipefd, FILENAME, sem);
        }
        default: { 
            parent_process(pipefd, FILENAME, pid, sem);
        }
    }
    sem_close(sem);
    sem_unlink("/numbers");
    return 0;
}