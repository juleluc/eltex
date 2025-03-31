#include "main.h"


int main(){

    while(1){
        choice();   
        int choice_number;     
        float number1;
        float number2;
        double result = 0;
        int count;
        if (scanf("%d", &choice_number) != 1){
            printf("Некорректный ввод\n");
            return -1;
        }

        switch (choice_number)
        {
        case 1:{
            double *numbers = get_array_value(&count);
            if (numbers != NULL){
                double result = addition(count, numbers);
                printf("Результат: %.3lf\n", result);
                free(numbers);
            }
            break;
        }
        case 2:{
            double *numbers = get_array_value(&count);
            if (numbers != NULL){
                double result = subtraction(count, numbers);
                printf("Результат: %.3lf\n", result);
                free(numbers);
            }
            break;
        }
        case 3:{
            double *numbers = get_array_value(&count);
            if (numbers != NULL){
                double result = multiplication(count, numbers);
                printf("Результат: %.3lf\n", result);
                free(numbers);
            }else{
                printf("Введите больше 1 чилса\n");
            }
            break;
        }
        case 4:{
            double * numbers = get_array_value(&count);
            for (int i = 1; i < count; i++){
                if (numbers[i] == 0){
                    printf("Деление на ноль\n");
                    return 1;
                }
            }
            if (numbers != NULL){
                double result = division(count, numbers);
                printf("Результат: %.3lf\n", result);
                free(numbers);
            }else{
                printf("Введите больше 1 числа\n");
            }
            break;
        }
        case 5:
            return 0;
        default:
            break;
        }

    }
    return 0;

}