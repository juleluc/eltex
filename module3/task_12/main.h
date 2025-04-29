#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <time.h>
#include <sys/sem.h>
#include <signal.h>
#define FILENAME "numbers.txt"
#define PROJ_ID 'B'
#define MAX_NUMBERS 50

union semun {
    int val;                
    struct semid_ds *buf;   
    unsigned short *array;  
    struct seminfo *__buf;  
};

typedef struct SharedData {
    int numbers[MAX_NUMBERS];
    int count;
    int min;
    int max;
    int processed_data_sets;
} SharedData;

extern struct SharedData *shared_data;

void free_shm_sem(int shm_id, int sem_id);
void init_shmget(int *shm_id);
void semaphore_unlock(int sem_id, int sem_idx);
void generate_numbers(int *numbers, int *count);
void semaphore_lock(int sem_id, int sem_idx);
void init_semaphore(int *sem_id);
void signal_handler(int signal);
#endif