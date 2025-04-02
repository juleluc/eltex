#include "main.h"

int main(){

    while (1){
        display_menu();
        int operation;
        int count;
        if (scanf("%d", &operation) != 1){
            printf("Некорректный ввод\n");
            while (getchar() != '\n');
            continue;
        }

        switch (operation){

        case 1:
        case 2:
        case 3:
        case 4:{
            double *numbers = get_array_value(&count);
            if (numbers != NULL){
                double result;
                int status = perform_operation(operation, count, numbers, &result);
                if (status == -1){
                    printf("Ошибка: Деление на ноль\n");
                }
                else{
                    printf("Результат: %.3lf\n", result);
                }
                free(numbers);
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


void display_menu()
{
    printf("1.Сложение\n");
    printf("2.Вычитание\n");
    printf("3.Умножение\n");
    printf("4.Деление\n");
    printf("5.Завершить программу\n");
}