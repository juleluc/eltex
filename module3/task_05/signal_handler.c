#include "main.h"


void signal_handler(int signal) {
    switch (signal) {
        case SIGUSR1:
            printf("Процесс %d: получает сигнал SIGUSR1 (блокировка)\n", getpid());
            flag_block = 1;
            break;

        case SIGUSR2:
            printf("Процесс %d: получает сигнал SIGUSR2 (разблокировка)\n", getpid());
            flag_block = 0;
            break;
    }
}