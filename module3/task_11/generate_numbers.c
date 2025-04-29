#include "main.h"


void generate_numbers(char *filename, int number){
    FILE *file = fopen(filename, "w");
    if (file == NULL){
        perror("Не удалось открыть файл\n");
        exit(EXIT_FAILURE);
    }
    int num;
    for (int i = 0; i < number; i++){
        num = rand() % 100;
        fprintf(file, "%d\n", num);
    }
    fclose(file);
}