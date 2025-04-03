#include "main.h"

int read_file(Contact *contacts, int *number, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        return 0;
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

        contacts[*number] = new_contact;
        (*number)++;
    }

    fclose(file);
    return 1;
}


int main()
{

    Contact people[MAX_CONTACT] = {0};
    int number = 0;
    int number_choice;

    if (!read_file(people, &number, "test.txt")) {
        printf("Ошибка загрузки контактов\n");
    } else {
        printf("Контакты успешно загружены из файла\n");
    }
    while (1)
    {

        display_menu();
        scanf("%d", &number_choice);

        switch (number_choice)
        {
        case 1:
            add_contact(people, &number);
            break;
        case 2:
            find_contact(people, number);
            break;
        case 3:
            delete_contact(people, &number);
            break;
        case 4:
            edit_contact(people, number);
            break;
        case 5:
            show_list_contacts(people, number);
            break;
        case 6:
            printf("Программа завершена\n");
            return 1;
        default:
            printf("Выберите из предложенного списка:\n\n");
            break;
        }
    }
    return 0;
}