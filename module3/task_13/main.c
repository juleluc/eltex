#include "main.h"


struct SharedData *shared_data;


int main()
{
    sem_t *sem_child;
    sem_t *sem_parent;
    int shm_id;
    pid_t pid;
    srand(time(NULL));

    init_shmopen(&shm_id);
    shared_data->count = 0;
    shared_data->max = 0;
    shared_data->min = 0;
    shared_data->processed_data_sets = 0;
    init_semaphore(&sem_child, &sem_parent);

    signal(SIGINT, signal_handler);
    switch (pid = fork()){
    case -1:
        perror("fork");
        free_shm_sem(sem_child, sem_parent);
        exit(EXIT_FAILURE);
    case 0:
        printf("Child %d: process\n", getpid());
        while (1){
            sem_wait(sem_child);
            usleep(500000);

            int min = shared_data->numbers[0];
            int max = shared_data->numbers[0];

            for (int i = 0; i < shared_data->count; i++){
                if (shared_data->numbers[i] < min){
                    min = shared_data->numbers[i];
                }

                if (shared_data->numbers[i] > max){
                    max = shared_data->numbers[i];
                }
            }


            shared_data->min = min;
            shared_data->max = max;
            sem_post(sem_parent);

        }
        exit(EXIT_SUCCESS);
    default:
        while(1){
            printf("\nParent %d: process\n", getpid());
            generate_numbers(shared_data->numbers, &shared_data->count);


            printf("наборы (%d чисел): ", shared_data->count);
            for (int i = 0; i < shared_data->count; i ++){
                printf("%d ", shared_data->numbers[i]);
            }

            sem_post(sem_child);
            sem_wait(sem_parent);

            printf("\nMin = %d, Max = %d\n", shared_data->min, shared_data->max);

            shared_data->processed_data_sets++;
        }

        wait(NULL);
        free_shm_sem(sem_child, sem_parent);
    }

    return 0;
}