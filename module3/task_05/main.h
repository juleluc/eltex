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

#define FILENAME "numbers.txt"

extern int flag_block;

void parent_process(int pipefd[2], char *filename, pid_t child_pid);
void child_process(int pipefd[2], char *filename);
void signal_handler(int signal);
void generate_numbers(char *filename, int number);
#endif