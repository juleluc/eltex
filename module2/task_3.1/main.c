#include "main.h"

int main() {
    char input[20];
    int choice;
    char filename[256];
    int num;

while(1){

    menu();
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Введите права доступа в буквенном обозначении 9-ти символов(например, rwxr-xr--): ");
        scanf("%s", input);

        if (strlen(input) != 9) {
            printf("Некорректный ввод\n");
            continue;
        }

        num = convert_char_to_bits(input);
        display_rights(num);

    } else if (choice == 2) {

        printf("Введите права доступа в цифровом обозначении (до 777): ");
        if(scanf("%o", &num) != 1 || num > 0777){
            printf("Ошибка: Введите число от 0 до 777.\n");
            continue;
        }

        display_rights(num);

    } else if (choice == 3){

        printf("Введите имя файла:\n");
        scanf("%s", filename);

        struct stat file_stat;
        if(stat(filename, &file_stat) == -1){
            perror("Ошибка при получении информации о файле");
            continue;
        }

        num = file_stat.st_mode & 0777; 
        display_rights(num);
     
    } else if (choice == 4){

        char buf[10];
        convert_num_to_char(num, buf);
        printf("Текущие права %o или %s:\n", num, buf);
    
        char command[20];
        printf("Введите команду модификации (например, u+rwx, g-w, o+x): ");
        scanf("%s", command);

        num = modify_rights(num, command);
        display_rights(num);

    } else if (choice == 5){
        printf("Программа завершена\n");
        break;
    } else {
        printf("Введите из доступных операций:\n");
        continue;
    }
}
    return 0;
}


