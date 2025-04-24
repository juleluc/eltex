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
    int sem_id;
    if (pipe(pipefd) == -1) {
        perror("Create pipe");
        exit(EXIT_FAILURE);
    }
    srand(time(NULL));
    generate_numbers(FILENAME, number);
    init_semaphore(&sem_id);

    switch (pid = fork()) {
        case -1:
            perror("fork");
            exit(EXIT_FAILURE);

        case 0: { 
            child_process(pipefd, FILENAME, sem_id);
        }
        default: { 
            parent_process(pipefd, FILENAME, pid, sem_id);
        }
    }

    if (semctl(sem_id, 0, IPC_RMID) == -1) {
        perror("semctl cleanup");
    }
    return 0;
}