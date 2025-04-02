#include "main.h"

int main()
{
    int (*operation_func[])(int, double *, double *) = {addition, subtraction, multiplication, division};

    while (1){
        display_menu();
        int operation;
        int count;
        if (scanf("%d", &operation) != 1){
            printf("Некорректный ввод\n");
            while (getchar() != '\n');
            continue;
        }

        if (operation < 1 || operation > 5){
            printf("Введите из доступных операций: \n");
            continue;
        }
        else if (operation != 5){
            double *numbers = get_array_value(&count);
            if (numbers != NULL){
                double result;
                int status = operation_func[operation - 1](count, numbers, &result);
                if (status == -1){
                    printf("Ошибка: Деление на ноль\n");
                }else{
                    printf("Результат: %.3lf\n", result);
                }
                free(numbers);
            }
        }else{
            return 0;
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