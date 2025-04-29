#include "main.h"


void init_shmopen(int *shm_id){

    *shm_id = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
    if (*shm_id == -1){
        perror("shm_open");
        exit(EXIT_FAILURE);
    }

    if (ftruncate(*shm_id, sizeof(SharedData)) == -1){
        perror("ftruncate");
        close(*shm_id);
        exit(EXIT_FAILURE);
    }

    shared_data = mmap(NULL, sizeof(SharedData), PROT_READ | PROT_WRITE, MAP_SHARED, *shm_id, 0);
    if (shared_data == MAP_FAILED){
        perror("mmap");
        close(*shm_id);
        exit(EXIT_FAILURE);
    }
    close(*shm_id);


}

void free_shm_sem(sem_t *sem_child, sem_t *sem_parent){
    if (shared_data != NULL){
        munmap(shared_data, sizeof(shared_data));
        shm_unlink(SHM_NAME);
    }

    if (sem_child != NULL){
        sem_close(sem_child);
        sem_unlink(SEM_CHILD_NAME);
    }

    if (sem_parent != NULL){
        sem_close(sem_parent);
        sem_unlink(SEM_PARENT_NAME);
    }
}

void init_semaphore(sem_t **sem_child, sem_t **sem_parent){
    *sem_child = sem_open(SEM_CHILD_NAME, O_CREAT, 0666, 0);
    *sem_parent = sem_open(SEM_PARENT_NAME, O_CREAT, 0666, 1);

    if (*sem_child == SEM_FAILED|| *sem_parent == SEM_FAILED){
        perror("sem_open");
        //free
        exit(EXIT_FAILURE);
    }


}


void signal_handler(int signal){
    printf("Получен сигнал SIGINT\n");
    printf("Количество обработанных запросов %d\n", shared_data->processed_data_sets);
    exit(EXIT_SUCCESS);
}


void generate_numbers(int *numbers, int *count){
    *count = rand() % MAX_NUMBERS;
    for (int i = 0; i < *count; i++){
        numbers[i] = rand() % 100;
    }
}