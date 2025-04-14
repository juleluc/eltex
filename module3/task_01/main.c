#include "main.h"


float *process_arg(int argc, char *argv[], int num_arg){
    if (argc < 2) {
        fprintf(stderr, "Введите: %s arg_1 arg_2 ... arg_N\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    num_arg = argc - 1;
    float *array = malloc((num_arg) * sizeof(float));
    if (array == NULL){
        perror("Ошибка выделения памяти\n");
        exit(EXIT_FAILURE);
    }


    for (int i = 0; i < num_arg; i++){
        array[i] = atof(argv[i + 1]);    
    }

    return array;
}


int main(int argc, char *argv[]) {

    int num_arg = argc - 1;
    float *array = process_arg(argc, argv, num_arg);

    pid_t pid;
    int rv;

    switch (pid = fork()) {
        case -1: {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        case 0: { 
            printf("Child: PID - %d\n", getpid());
            printf("Child: PPID - %d\n", getppid());

            int part = num_arg / 2;
            calculate_area(array, part, getpid());
            exit(EXIT_SUCCESS);
        }
        default: { 
            printf("Parent: PID - %d\n", getpid());
            printf("Parent: CHILD PID - %d\n", pid);

            int part = num_arg - (num_arg / 2);
            calculate_area(array + (num_arg / 2), part, getpid());
            wait(&rv); 
            printf("PARENT: RETURN STATUS FOR CHILD- %d\n", WEXITSTATUS(rv));
        }
    }

    return 0;
}