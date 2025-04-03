#include "main.h"
#include <dlfcn.h>

typedef int (*operation_func)(int, double *, double *);

int main()
{
    void *handle_add;
    void *handle_sub;
    void *handle_mult;
    void *handle_div;

    operation_func addition, subtraction, multiplication, division;

    handle_add = dlopen("./operation/libadd.so", RTLD_LAZY);
    handle_sub = dlopen("./operation/libsub.so", RTLD_LAZY);
    handle_mult = dlopen("./operation/libmult.so", RTLD_LAZY);
    handle_div = dlopen("./operation/libdiv.so", RTLD_LAZY);

    if(!handle_add || !handle_sub || !handle_mult || !handle_div){
        fprintf(stderr, "Ошибка загрузки библиотеки: %s\n", dlerror());
        exit(1);
    }

    addition = (operation_func) dlsym(handle_add, "addition");
    subtraction = (operation_func) dlsym(handle_sub, "subtraction");
    multiplication = (operation_func) dlsym(handle_mult, "multiplication");
    division = (operation_func) dlsym(handle_div, "division");

    if(!addition || !subtraction || !multiplication || !division){
        fprintf(stderr, "Ошибка получения функции: %s\n", dlerror());
        dlclose(handle_add);
        dlclose(handle_sub);
        dlclose(handle_mult);
        dlclose(handle_div);
        exit(1);
    }

    operation_func operations[] = {addition, subtraction, multiplication, division};

    while (1){
        display_menu();
        int choice;
        int count;
        if (scanf("%d", &choice) != 1){
            printf("Некорректный ввод\n");
            while (getchar() != '\n');
            continue;
        }

        if (choice < 1 || choice > 5){
            printf("Введите из доступных операций: \n");
            continue;
        }
        else if (choice != 5){
            double *numbers = get_array_value(&count);
            if (numbers != NULL){
                double result;
                int status = operations[choice - 1](count, numbers, &result);
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

    dlclose(handle_add);
    dlclose(handle_sub);
    dlclose(handle_mult);
    dlclose(handle_div);

    return 0;
}

