#include "main.h"

void input_data_contact(const char *title, char *data) {
    char buffer[MAX_LENGHT];
    printf("%s\n", title);
    scanf("%s", buffer);
    if (strcmp(buffer, "skip") != 0) {
        strcpy(data, buffer);
    } 
}

void input_array_contact_info(const char *title, char array[][MAX_LENGHT], int max_count){
    char buffer[MAX_LENGHT];
    for(int i = 0; i < max_count; i++){
        printf("%s %d:\n", title, i + 1);
        scanf("%s", buffer);
        if(strcmp(buffer, "skip") != 0){
            strcpy(array[i], buffer);
        }else{
            break;
        }
    }
}

void add_contact(Contact *contacts, int *number) {
    if (*number >= MAX_CONTACT) {
        printf("Список контактов переполнен\n");
        return;
    }

    Contact new_contact = {0};

    input_data_contact("Введите Имя", new_contact.name.FirstName);
    input_data_contact("Введите Фамилию", new_contact.name.LastName);

    input_data_contact("Введите Место работы (Пропустить: skip)", new_contact.job_place.company);
    input_data_contact("Введите Должность (Пропустить: skip)", new_contact.job_place.position);

    input_array_contact_info("Введите Телефон (Пропустить: skip)", new_contact.contact_info.phone_number, COUNT_VALUE);
    input_array_contact_info("Введите Email (Пропустить: skip)", new_contact.contact_info.emails, COUNT_VALUE);
    input_array_contact_info("Введите Соцсети (Пропустить: skip)", new_contact.contact_info.social_link, COUNT_VALUE);
    input_array_contact_info("Введите Мессенджеры (Пропустить: skip)", new_contact.contact_info.messenger_profiles, COUNT_VALUE);

    contacts[*number] = new_contact;
    (*number)++;
    printf("Контакт добавлен\n");
}

void delete_contact(Contact *contacts, int *number_contacts) {
    char FirstName[MAX_LENGHT];
    char LastName[MAX_LENGHT];
    printf("Введите Имя и Фамилию\n");
    scanf("%s %s", FirstName, LastName);

    for (int i = 0; i < *number_contacts; i++) {
        if (strcmp(contacts[i].name.FirstName, FirstName) == 0 &&
            strcmp(contacts[i].name.LastName, LastName) == 0) {

            for (int j = i; j < *number_contacts - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            (*number_contacts)--;
            printf("Контакт удален\n");
            return;
        }
    }
    printf("Контакт не найден\n");
}

void edit_contact(Contact *contact, int number_contact)
{
    char first_name[MAX_LENGHT];
    char last_name[MAX_LENGHT];
    printf("Введите имя и фамилию для редактирования:\n");
    scanf("%s %s", first_name, last_name);

    for (int i = 0; i < number_contact; i++) {
        if (strcmp(contact[i].name.FirstName, first_name) == 0 &&
            strcmp(contact[i].name.LastName, last_name) == 0) {
            printf("Редактируйте данные контакта:\n");

            input_data_contact("Введите новое имя (или skip для пропуска):", contact[i].name.FirstName);
            input_data_contact("Введите новую фамилию (или skip для пропуска):", contact[i].name.LastName);
            input_data_contact("Введите новое место работы (или skip для пропуска):", contact[i].job_place.company);
            input_data_contact("Введите новую должность (или skip для пропуска):", contact[i].job_place.position);

            input_array_contact_info("Введите новые телефоны (или skip для пропуска):", contact[i].contact_info.phone_number, COUNT_VALUE);
            input_array_contact_info("Введите новые email'ы (или skip для пропуска):", contact[i].contact_info.emails, COUNT_VALUE);
            input_array_contact_info("Введите новые соцсети (или skip для пропуска):", contact[i].contact_info.social_link, COUNT_VALUE);
            input_array_contact_info("Введите новые мессенджеры (или skip для пропуска):", contact[i].contact_info.messenger_profiles, COUNT_VALUE);

            printf("Контакт обновлен\n");
            return;
        }
    }

    printf("Контакт не найден\n");
}

void find_contact(Contact *contacts, int number_contacts) {
    char FirstName[MAX_LENGHT];
    char LastName[MAX_LENGHT];
    printf("Введите имя и Фамилию\n");
    scanf("%s %s", FirstName, LastName);

    for (int i = 0; i < number_contacts; i++) {
        if (strcmp(contacts[i].name.FirstName, FirstName) == 0 &&
            strcmp(contacts[i].name.LastName, LastName) == 0) {
            print_display(&contacts[i]);
            return;
        }
    }
    printf("Контакт не найден\n");
}