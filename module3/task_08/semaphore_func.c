#include "main.h"


void lock_semaphore(int sem_id){
    struct sembuf sb = {0, -1, 0};
    if (semop(sem_id, &sb, 1) == -1){
        perror("semop");
        exit(EXIT_FAILURE);
    }
}

void unlock_semaphore(int sem_id){
    struct sembuf sb = {0, 1, 0};
    if (semop(sem_id, &sb, 1) == -1){
        perror("semop");
        exit(EXIT_FAILURE);
    }
}

void init_semaphore(int *sem_id){
    key_t key = ftok(FILENAME, PROG_ID);
    if (key == -1){
        perror("ftok");
        exit(EXIT_FAILURE);
    }

    *sem_id = semget(key, 1, 0666 | IPC_CREAT);
    if (*sem_id == -1){
        perror("semget");
        exit(EXIT_FAILURE);
    }

    union semun sem_union;
    sem_union.val = 1; 
    if (semctl(*sem_id, 0, SETVAL, sem_union) == -1) {
        perror("semctl");
        exit(EXIT_FAILURE);
    }
}