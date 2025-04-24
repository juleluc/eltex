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
#define PROG_ID 'B'
#define FILENAME "numbers.txt"
#define READERS_COUNT 2
union semun {
    int val;                
    struct semid_ds *buf;   
    unsigned short *array;  
    struct seminfo *__buf;  
};

void reader_process(int pipefd[2], char *filename, int sem_id);
void writer_process(int pipefd[2], char *filename, pid_t child_pid, int sem_id);
void child_process(int pipefd[2], char *filename, int sem_id);
void generate_numbers(char *filename, int number);

void sem_op(int sem_id, int sem_num, int op);
void writer_lock(int sem_id);
void writer_unlock(int sem_id);
void reader_unlock(int sem_id);
void reader_lock(int sem_id);
void init_semaphore(int *sem_id);
#endif