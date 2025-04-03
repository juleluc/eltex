#include "main.h"


int main() {
    ContactNode *head = NULL; 
    int operation;

    while (1) {
        display_menu();
        if (scanf("%d", &operation) != 1){
            printf("Некорректный ввод\n");
            while (getchar() != '\n');
            continue;
        }
        char FirstName[MAX_LENGHT];
        char LastName[MAX_LENGHT];

        switch (operation) {
            case 1: {
                Contact new_contact = {0};
                wrap_input_data_contact(&new_contact);
                head = add_contact_sorted(head, new_contact);
                break;
            }
            case 2: {
                printf("Введите имя и Фамилию\n");
                input_name(FirstName, LastName);

                ContactNode *node = find_contact(head, FirstName, LastName);
                if (node != NULL) {
                    print_display(&node->data);
                } else {
                    printf("Контакт не найден\n");
                }
                break;
            }
            case 3: {
                printf("Введите имя и Фамилию\n");
                input_name(FirstName, LastName);

                head = delete_contact(head, FirstName, LastName);
                break;
            }
            case 4: {
                printf("Введите имя и Фамилию для редактирования\n");
                input_name(FirstName, LastName);

                edit_contact(head, FirstName, LastName);
                break;
            }
            case 5:
                show_list_contacts(head);
                break;
            case 6:
                free_list(head);
                printf("Программа завершена\n");
                return 0;
            default:
                printf("Выберите из предложенного списка:\n\n");
                break;
        }
    }
}

