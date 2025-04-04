#include "main.h"

void menu(){
    printf("1. Буквенное обозначение\n");
    printf("2. Цифровое обозначение\n");
    printf("3. Получить права доступа файла\n");
    printf("4. Изменить права доступа\n");
    printf("5. Выход\n");
}


void display_rights(int num){
    char buf[10];
    convert_num_to_char(num, buf);

    printf("Права доступа:\n");
    printf("Буквенное представление: %s\n", buf);
    printf("Цифровое представление: %o\n", num);
    print_bit(num);
}