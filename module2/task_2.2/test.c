#include "main.h"

void print_array(double numbers[], size_t size) {
    printf("Исходные значения: ");
    for (size_t i = 0; i < size; i++) {
        printf("%.2lf ", numbers[i]);
    }
    printf("\n");
}

int main() {

    printf("Сложение\n");
    double numbers_add[] = {1.0, 2.0, 3.0};
    size_t size_add = sizeof(numbers_add) / sizeof(numbers_add[0]);
    print_array(numbers_add, size_add);
    double result_add;
    int status_add = addition(size_add, numbers_add, &result_add);
    if (status_add == 0) {
        printf("Result: %.2lf\n", result_add);
    } else {
        printf("Error\n");
    }
    printf("\n");

    printf("Вычитание\n");
    double numbers_sub[] = {10.0, 4.0, 2.0};
    size_t size_sub = sizeof(numbers_sub) / sizeof(numbers_sub[0]);
    print_array(numbers_sub, size_sub);
    double result_sub;
    int status_sub = subtraction(size_sub, numbers_sub, &result_sub);
    if (status_sub == 0) {
        printf("Result: %.2lf\n", result_sub);
    } else {
        printf("Error\n");
    }
    printf("\n");



    printf("Умножение\n");
    double numbers_mul[] = {2.0, 3.0, 4.0};
    size_t size_mul = sizeof(numbers_mul) / sizeof(numbers_mul[0]);
    print_array(numbers_mul, size_mul);
    double result_mul;
    int status_mul = multiplication(size_mul, numbers_mul, &result_mul);
    if (status_mul == 0) {
        printf("Result: %.2lf\n", result_mul);
    } else {
        printf("Error\n");
    }
    printf("\n");



    printf("Деление\n");
    double numbers_div[] = {100.0, 10.0, 2.0};
    size_t size_div = sizeof(numbers_div) / sizeof(numbers_div[0]);
    print_array(numbers_div, size_div);
    double result_div;
    int status_div = division(size_div, numbers_div, &result_div);
    if (status_div == 0) {
        printf("Result:%.2lf\n", result_div);
    } else {
        printf("Error\n");
    }
    printf("\n");


    
    printf("Деление на ноль\n");
    double numbers_div_zero[] = {100.0, 0, 2.0};
    size_t size_div_zero = sizeof(numbers_div_zero) / sizeof(numbers_div_zero[0]);
    print_array(numbers_div_zero, size_div_zero);
    double result_div_zero;
    int status_div_zero = division(size_div_zero, numbers_div_zero, &result_div_zero);
    if (status_div_zero == 0) {
        printf("Result:%.2lf\n", result_div_zero);
    } else {
        printf("Error: Деление на ноль\n");
    }

    return 0;
}