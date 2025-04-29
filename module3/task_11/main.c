#include "main.h"


int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Введите: %s value\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int number = atoi(argv[1]);
    int rv;
    int pipefd[2];
    pid_t pids[READERS_COUNT];
    sem_t *readers_count;
    sem_t *writers_lock;
    sem_t *readers_lock;

    if (pipe(pipefd) == -1) {
        perror("Create pipe");
        exit(EXIT_FAILURE);
    }
    srand(time(NULL));

    generate_numbers(FILENAME, number);
    init_semaphore(&readers_count, &writers_lock, &readers_lock);



    for (int i = 0; i < READERS_COUNT; i++){
        if ((pids[i] = fork()) == -1){
            perror("fork");
            exit(EXIT_FAILURE);
        }
        if (pids[i] == 0){
            reader_process(pipefd, FILENAME, readers_count, writers_lock, readers_lock);
        }

    }
    
    writer_process(pipefd, FILENAME, pids[0], readers_count, writers_lock, readers_lock);

    for (int i = 0; i < READERS_COUNT; i++){
        waitpid(pids[i], NULL, 0);
    }

    semaphore_free(readers_count, writers_lock, readers_lock);

    return 0;
}