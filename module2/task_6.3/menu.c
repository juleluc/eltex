#include "main.h"

void display_menu()
{
    printf("1.Сложение\n");
    printf("2.Вычитание\n");
    printf("3.Умножение\n");
    printf("4.Деление\n");
    printf("5.Завершить программу\n");
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