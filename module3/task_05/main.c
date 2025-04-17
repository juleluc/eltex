#include "main.h"

int flag_block = 0;

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
    signal(SIGUSR1, signal_handler);
    signal(SIGUSR2, signal_handler);
    generate_numbers(FILENAME, number);

    switch (pid = fork()) {
        case -1:
            perror("fork");
            exit(EXIT_FAILURE);

        case 0: { 
            child_process(pipefd, FILENAME);
        }
        default: { 
            parent_process(pipefd, FILENAME, pid);
        }
    }

    return 0;
}