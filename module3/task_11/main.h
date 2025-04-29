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
#include <semaphore.h>
#define FILENAME "numbers.txt"
#define READERS_COUNT 2

void writer_process(int pipefd[2], char *filename, pid_t child_pid, sem_t *readers_count, sem_t *writers_lock, sem_t *readers_lock);
void reader_process(int pipefd[2], char *filename, sem_t *readers_count, sem_t *writers_lock, sem_t *readers_lock);
void generate_numbers(char *filename, int number);
void init_semaphore(sem_t **readers_count, sem_t **writers_lock, sem_t **readers_lock);
void semaphore_free(sem_t *readers_count, sem_t *writers_lock, sem_t *readers_lock);
#endif