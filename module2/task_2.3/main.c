#include "main.h"

int main(){

    while (1){
        choice();
        int choice_number;
        float number1;
        float number2;
        double result = 0;
        int count;
        if (scanf("%d", &choice_number) != 1 || choice_number < 1){
            printf("Некорректный ввод\n");
            return -1;
        }

        if (choice_number > 5){
            printf("Введите из доступных операций: \n");
            continue;
        }
        else if (choice_number != 5){

            double (*operation[4])(int, double *) = {addition, subtraction, multiplication, division};
            double *numbers = get_array_value(&count);
            if (choice_number == 4){
                for (int i = 1; i < count; i++){
                    if (numbers[i] == 0){
                        printf("Деление на ноль\n");
                        return 1;
                    }
                }
            }

            if (numbers != NULL){
                result = operation[choice_number - 1](count, numbers);
                printf("Результат: %.3lf\n", result);
                free(numbers);
            }
        }
        else
            return 0;
    }
}