#ifndef MAIN_H
#define MAIN_H
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <signal.h>
#include <sys/sem.h>
#include <sys/ipc.h>
#define PROG_ID 'A'
#define FILENAME "numbers.txt"

union semun {
    int val;                
    struct semid_ds *buf;   
    unsigned short *array;  
    struct seminfo *__buf;  
};

void parent_process(int pipefd[2], char *filename, pid_t child_pid, int sem_id);
void child_process(int pipefd[2], char *filename, int sem_id);
void signal_handler(int signal);
void generate_numbers(char *filename, int number);
void unlock_semaphore(int sem_id);
void lock_semaphore(int sem_id);
void init_semaphore(int *sem_id);
#endif