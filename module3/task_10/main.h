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

void parent_process(int pipefd[2], char *filename, pid_t child_pid, sem_t *sem);
void child_process(int pipefd[2], char *filename, sem_t *sem);
void generate_numbers(char *filename, int number);
#endif