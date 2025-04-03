#include "../main.h"

int subtraction(int n, double numbers[], double *result){
    *result = numbers[0];
    for (int i = 1; i < n; i++)
    {
        *result -= numbers[i];
    }
    return 0;
}