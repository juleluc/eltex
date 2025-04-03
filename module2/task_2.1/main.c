#include "main.h"

int main() {
    Contact people[MAX_CONTACT] = {0};
    int number = 0;
    int number_choice;

    while (1) {
        display_menu();
        scanf("%d", &number_choice);

        switch (number_choice) {
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
                return 0;
            default:
                printf("Выберите из предложенного списка:\n\n");
                break;
        }
    }
}