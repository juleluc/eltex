#include "main.h"



int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Введите: %s value\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int number = atoi(argv[1]);
    pid_t pids[READERS_COUNT];
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


    for (int i = 0; i < READERS_COUNT; ++i) {
        if ((pids[i] = fork()) == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (pids[i] == 0) { 
            reader_process(pipefd, FILENAME, sem_id);
        }
    }

    writer_process(pipefd, FILENAME, pids[0], sem_id);


    for (int i = 0; i < READERS_COUNT; ++i) {
        waitpid(pids[i], NULL, 0);
    }

    if (semctl(sem_id, 0, IPC_RMID) == -1) {
        perror("semctl cleanup");
    }

    return 0;
}