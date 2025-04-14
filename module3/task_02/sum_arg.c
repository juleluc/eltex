#include <stdio.h>
#include <stdlib.h>



int main(int argc, char *argv[]){

    float total_sum;
    float current_value;

    for (int i = 0; i < argc; i ++){
        current_value = atof(argv[i]);
        total_sum += current_value;
    }

    printf("%.2f\n", total_sum);

    return 0;
}