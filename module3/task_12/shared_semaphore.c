#include "main.h"



void signal_handler(int signal){
    printf("Получен сигнал SIGINT\n");
    printf("Количество обработанных запросов %d\n", shared_data->processed_data_sets);
    exit(EXIT_SUCCESS);
}


void init_semaphore(int *sem_id){
    key_t key = ftok(FILENAME, PROJ_ID);
    if (key == -1){
        perror("ftok");
        exit(EXIT_FAILURE);
    }

    *sem_id = semget(key, 2, IPC_CREAT | 0666);
    if (*sem_id == -1){
        perror("semget");
        exit(EXIT_FAILURE);
    }

    union semun sem_union;
    sem_union.val = 0; // lock for child process
    if (semctl(*sem_id, 0, SETVAL, sem_union) == -1){
        perror("semctl sem 0");
        exit(EXIT_FAILURE);
    }

    sem_union.val = 1; // unlock for parent process
    if (semctl(*sem_id, 1, SETVAL, sem_union) == -1){
        perror("semctl sem 1");
        exit(EXIT_FAILURE);
    }
}


void semaphore_lock(int sem_id, int sem_idx){
    struct sembuf sb = {sem_idx, -1, 0};
    if (semop(sem_id, &sb, 1) == -1){
        perror("semop lock");
        exit(EXIT_FAILURE);
    }
}

void generate_numbers(int *numbers, int *count){
    *count = rand() % MAX_NUMBERS;
    for (int i = 0; i < *count; i++){
        numbers[i] = rand() % 100;
    }
}

void semaphore_unlock(int sem_id, int sem_idx){
    struct sembuf sb = {sem_idx, 1, 0};
    if (semop(sem_id, &sb, 1) == -1){
        perror("sem unlock");
        exit(EXIT_FAILURE);
    }
}
void init_shmget(int *shm_id){

    key_t key = ftok(FILENAME, PROJ_ID);
    if (key == -1)
    {
        perror("ftok");
        exit(EXIT_FAILURE);
    }

    *shm_id = shmget(key, sizeof(shared_data), IPC_CREAT | 0666);
    if (*shm_id == -1){
        perror("shmget");
        exit(EXIT_FAILURE);
    }
    
    // link shared_memory to addr
    shared_data = (struct SharedData *)shmat(*shm_id, NULL, 0);
    if (shared_data == (void *)-1){
        perror("shmat");
        exit(EXIT_FAILURE);
    }
}

void free_shm_sem(int shm_id, int sem_id){

    if (shmdt(shared_data) == -1){
        perror("shmdt");
    }

    if (shmctl(shm_id, IPC_RMID, NULL) == -1){
        perror("shmctl");
    }

    if (semctl(sem_id, 0, IPC_RMID) == -1){
        perror("semctl");
    }

}