#include "../main.h"

int addition(int n, double numbers[], double *result){   
    *result = 0;
    for (int i = 0; i < n; i++)
    {
        *result += numbers[i];
    }
    return 0;
}