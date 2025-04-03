#include "../main.h"

int division(int n, double numbers[], double *result){
    *result = numbers[0];
    for (int i = 1; i < n; i++){
        if(numbers[i] == 0){
            return -1;
        }
        *result /= numbers[i];
    }
    return 0;
}