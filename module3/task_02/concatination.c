#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ARGS 16

int main(int argc, char *argv[]){
    if(argc < 2){
        fprintf(stderr, "Введите: concatination str_1 str_2 ... str_N\n");
        exit(EXIT_FAILURE);
    }

    int length = 0;
    for (int i = 1; i < argc; i++){
        length += strlen(argv[i]);
    }

    char *result = malloc(length + 1);
    if (result == NULL){
        perror("Ошибка выделения памяти\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 1; i < argc; i++){
        strcat(result, argv[i]);
    }

    printf("Result: %s\n", result);

    free(result);
    
    return 0;
}