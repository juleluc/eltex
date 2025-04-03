#include "main.h"


ContactNode *read_contacts_from_file(ContactNode *head, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("не удалось открыть файл\n");
        return head; 
    }

    char line[512]; 
    while (fgets(line, sizeof(line), file)) {

        if (strlen(line) == 0) continue; 

        Contact new_contact = {0}; 

   
        char *sep = strtok(line, ",");
        if (!sep) continue; 


        strcpy(new_contact.name.FirstName, sep); 
        sep = strtok(NULL, ",");
        if (!sep) continue;
        strcpy(new_contact.name.LastName, sep); 

        sep = strtok(NULL, ",");
        if (sep && strcmp(sep, "") != 0) strcpy(new_contact.job_place.company, sep); 

        sep = strtok(NULL, ",");
        if (sep && strcmp(sep, "") != 0) strcpy(new_contact.job_place.position, sep); 

        sep = strtok(NULL, ",");
        if (sep && strcmp(sep, "") != 0) strcpy(new_contact.contact_info.phone_number[0], sep); 

        sep = strtok(NULL, ",");
        if (sep && strcmp(sep, "") != 0) strcpy(new_contact.contact_info.emails[0], sep); 

        sep = strtok(NULL, ",");
        if (sep && strcmp(sep, "") != 0) strcpy(new_contact.contact_info.social_link[0], sep); 

        sep = strtok(NULL, ",");
        if (sep && strcmp(sep, "") != 0) strcpy(new_contact.contact_info.messenger_profiles[0], sep); 


        head = add_contact_sorted(head, new_contact);
    }

    fclose(file); 
    return head; 
}

int main() {
    ContactNode *head = NULL; 
    int operation;

    head = read_contacts_from_file(head, "contacts.txt");
    if (head == NULL) {
        printf("Не удалось загрузить контакты из файла.\n");
    } else {
        printf("Контакты успешно загружены из файла.\n");
    }

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

