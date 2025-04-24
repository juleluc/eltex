#include "main.h"

void sem_op(int sem_id, int sem_num, int op) {
    struct sembuf sb = {sem_num, op, 0}; // op (-1 захват, +1 освобождение)
    if (semop(sem_id, &sb, 1) == -1) {
        perror("semop");
        exit(EXIT_FAILURE);
    }
}

void reader_lock(int sem_id) {
    sem_op(sem_id, 1, -1); // захват семафора 1 для счетчика читатлей
    sem_op(sem_id, 0, 1);  // освобождение сем. 0 (увел читателей)
    int val = semctl(sem_id, 0, GETVAL); // получаем знач счет читателей
    if (val == 1) {
        sem_op(sem_id, 2, -1);  // блок писателя если это читатель
    }
    sem_op(sem_id, 1, 1);  // освобождаем читателя
}

void reader_unlock(int sem_id) {
    sem_op(sem_id, 1, -1); 
    sem_op(sem_id, 0, -1); // уменьшаем счет читателей
    int val = semctl(sem_id, 0, GETVAL);
    if (val == 0) {
        sem_op(sem_id, 2, 1); // освобождение писателей если читателей нет
    }
    sem_op(sem_id, 1, 1);  // освобождаем читателя
}


void writer_lock(int sem_id) {
    sem_op(sem_id, 2, -1);  // захват писателя 
}


void writer_unlock(int sem_id) {
    sem_op(sem_id, 2, 1);  // освобождение писателя
}

void init_semaphore(int *sem_id) {
    key_t key = ftok(FILENAME, PROG_ID);
    if (key == -1) {
        perror("ftok");
        exit(EXIT_FAILURE);
    }

    *sem_id = semget(key, 3, IPC_CREAT | 0666);
    if (*sem_id == -1) {
        perror("semget");
        exit(EXIT_FAILURE);
    }

    union semun sem_union;

    sem_union.val = 0; // счётчик читателей
    if (semctl(*sem_id, 0, SETVAL, sem_union) == -1) {
        perror("semctl sem[0]");
        exit(EXIT_FAILURE);
    }

    sem_union.val = 1; // защита счетчика читателей (1 освобожден )
    if (semctl(*sem_id, 1, SETVAL, sem_union) == -1) {
        perror("semctl sem[1]");
        exit(EXIT_FAILURE);
    }

    sem_union.val = 1; // доступ читателей к файлу
    if (semctl(*sem_id, 2, SETVAL, sem_union) == -1) {
        perror("semctl sem[2]");
        exit(EXIT_FAILURE);
    }
}