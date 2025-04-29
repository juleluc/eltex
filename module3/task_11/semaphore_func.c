#include "main.h"

void init_semaphore(sem_t **readers_count, sem_t **writers_lock, sem_t **readers_lock){
    *readers_lock = sem_open("readers_lock", O_CREAT, 0666, 1);
    *readers_count = sem_open("/reader_count", O_CREAT, 0666, 0);
    *writers_lock = sem_open("writers_lock", O_CREAT, 0666, 1);

    if (*readers_count == SEM_FAILED || *writers_lock == SEM_FAILED || *readers_lock == SEM_FAILED){
        perror("sem_open");
        exit(EXIT_FAILURE);
    }
}


void semaphore_free(sem_t *readers_count, sem_t *writers_lock, sem_t *readers_lock){
    sem_close(readers_count);
    sem_close(writers_lock);
    sem_close(readers_lock);
    sem_unlink("/readers_count");
    sem_unlink("/writers_lock");
    sem_unlink("readers_lock");

}