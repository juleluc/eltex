#include "main.h"


void calculate_area(float *array, int size, pid_t pid) {
    printf("Process %d calculating areas:\n", pid);
    for (int i = 0; i < size; i++) {
        float area = array[i] * array[i];
        printf("length = %.2f, Area = %.2f\n", array[i], area);
    }
    printf("\n");
}