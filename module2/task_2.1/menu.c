#include "main.h"

void display_menu() {
    printf("---Телефонная книга---\n");
    printf("1.Добавить контакт\n");
    printf("2.Найти контакт\n");
    printf("3.Удалить контакт\n");
    printf("4.Редактировать контакт\n");
    printf("5.Список контактов\n");
    printf("6.Выход\n");
    printf("----------------------\n\n");
}

void print_contact_info(const char *title, const char array[][MAX_LENGHT], int count) {
    printf("%s:\n", title);
    for (int i = 0; i < count; i++) {
        if (strlen(array[i]) > 0) {
            printf("- %s\n", array[i]);
        }
    }
}

void print_display(const Contact *contact) {
    printf("Имя: %s\n", contact->name.FirstName);
    printf("Фамилия: %s\n", contact->name.LastName);

    if (strlen(contact->job_place.company) > 0) {
        printf("Место работы: %s\n", contact->job_place.company);
    }
    if (strlen(contact->job_place.position) > 0) {
        printf("Должность: %s\n", contact->job_place.position);
    }

    print_contact_info("Телефоны", contact->contact_info.phone_number, COUNT_VALUE);
    print_contact_info("Email'ы", contact->contact_info.emails, COUNT_VALUE);
    print_contact_info("Профили в мессенджерах", contact->contact_info.messenger_profiles, COUNT_VALUE);
    print_contact_info("Социальные сети", contact->contact_info.social_link, COUNT_VALUE);
}

int show_list_contacts(Contact *contacts, int number_contacts) {
    if (number_contacts == 0) {
        printf("-----------------------\n");
        printf("Список контактов пуст\n");
        printf("-----------------------\n\n");
        return 1;
    }

    printf("-----------------------\n");
    for (int i = 0; i < number_contacts; i++) {
        print_display(&contacts[i]);
    }
    return 0;
}