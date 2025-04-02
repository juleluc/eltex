#include "main.h"


int perform_operation(int operation, int count, double numbers[], double *result){
    switch (operation){
    case 1: return addition(count, numbers, result);
    case 2: return subtraction(count, numbers, result);
    case 3: return multiplication(count, numbers, result);
    case 4: return division(count, numbers, result);
    default: return -1;
    }
}

int addition(int n, double numbers[], double *result){   
    *result = 0;
    for (int i = 0; i < n; i++)
    {
        *result += numbers[i];
    }
    return 0;
}

int subtraction(int n, double numbers[], double *result){
    *result = numbers[0];
    for (int i = 1; i < n; i++)
    {
        *result -= numbers[i];
    }
    return 0;
}

int multiplication(int n, double numbers[], double *result){
    *result = numbers[0];
    for (int i = 1; i < n; i++)
    {
        *result *= numbers[i];
    }
    return 0;
}

int division(int n, double numbers[], double *result){
    *result = numbers[0];
    for (int i = 1; i < n; i++){
        if(numbers[i] == 0){
            return -1;
        }
        *result /= numbers[i];
    }
    return 0;
}

double *get_array_value(int *count){

    printf("Введите количество чисел для операции: \n");
    if (scanf("%d", count) != 1 || *count < 2){
        printf("Ошибка: кол-во чисел должно быть >= 2\n");
        return NULL;
    }

    double *numbers = (double *)malloc(*count * sizeof(double));
    if (numbers == NULL)
    {
        printf("Ошибка выделения памяти\n");
        exit(1);
    }

    printf("Введите %d чисел: \n", *count);
    for (int i = 0; i < *count; i++){
        if(scanf("%lf", &numbers[i]) != 1){
            printf("Некорректное значение\n");
            free(numbers);
            return NULL;
        }
    }
    return numbers;
}