#include "main.h"

void choice(){
    printf("1.Сложение\n");
    printf("2.Вычитание\n");
    printf("3.Умножение\n");
    printf("4.Деление\n");
    printf("5.Завершить программу\n");
}


double  addition(int n, double numbers[]){
    double result = 0;
    for(int i = 0; i < n; i++){
        result += numbers[i];
    }
    return result;
}

double subtraction(int n, double numbers[]){
    double result = numbers[0];
    for(int i = 1; i < n; i++){
        result -= numbers[i];
    }
    return result;
}

double multiplication(int n, double numbers[]){
    double result = numbers[0];
    for(int i = 1; i < n; i++){
        result *= numbers[i];
    }
    return result;
}

double division(int n, double numbers[]){
    double result = numbers[0];
    for(int i = 1; i < n; i++){
        result /= numbers[i];
    }
    return result;
}

double* get_array_value(int *count){

    printf("Введите количество чисел для операции: \n");
    scanf("%d", count);
    if (*count < 2){
        printf("Кол-во чисел: %d. введите >= 2\n", *count);
        return NULL;
    }
    double *numbers = (double*)malloc(*count * sizeof(double));
    if (numbers == NULL){
        printf("Ошибка выделения памяти\n");
        exit(1);
    }

    printf("Введите %d чисел: \n", *count);
    for(int i = 0; i < *count; i++){
        scanf("%lf", &numbers[i]);
    }
    return numbers;

}