#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <semaphore.h>
#include <signal.h>
#include <sys/wait.h>
#include <time.h>
#define SHM_NAME "/shared"
#define MAX_NUMBERS 50
#define SEM_CHILD_NAME "/sem_child"
#define SEM_PARENT_NAME "/sem_parent"

typedef struct SharedData {
    int numbers[MAX_NUMBERS];
    int count;
    int min;
    int max;
    int processed_data_sets;
} SharedData;

extern struct SharedData *shared_data;
void signal_handler(int signal);
void free_shm_sem(sem_t *sem_child, sem_t *sem_parent);
void generate_numbers(int *numbers, int *count);
void init_semaphore(sem_t **sem_child, sem_t **sem_parent);
void init_shmopen(int *shm_id);
#endif