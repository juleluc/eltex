#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]){
    if(argc < 2){
        fprintf(stderr, "Введите: max num_1 num_2 ... num_N\n");
        exit(EXIT_FAILURE);
    }

    float max = atof(argv[1]);
    for (int i = 2; i < argc; i++){
        int num = atof(argv[i]);
        if (num > max){
            max = num;
        }
    }

    printf("Max value: %.2f\n", max);
    return EXIT_SUCCESS;
}