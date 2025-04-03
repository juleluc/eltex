#include "main.h"


typedef ContactNode *(*add_func)(ContactNode *, Contact);
typedef ContactNode *(*del_func)(ContactNode *, const char *, const char *);
typedef ContactNode *(*find_func)(ContactNode *, const char *, const char *);
typedef void (*free_func)(ContactNode *);

int main() {

    void *handle;
    add_func add_contact_sorted;
    del_func delete_contact;
    find_func find_contact;
    free_func free_list;

    handle = dlopen("./liblist.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "Ошибка загрузки библиотеки: %s\n", dlerror());
        exit(1);
    }

    add_contact_sorted = (add_func)dlsym(handle, "add_contact_sorted");
    delete_contact = (del_func)dlsym(handle, "delete_contact");
    find_contact = (find_func)dlsym(handle, "find_contact");
    free_list = (free_func)dlsym(handle, "free_list");

    if(!add_contact_sorted || !delete_contact || !find_contact || !free_list){
        fprintf(stderr, "Ошибка получения функции: %s\n", dlerror());
        exit(1);
    }

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
                ContactNode *node = find_contact(head, FirstName, LastName);
                edit_contact(node);
                break;
            }
            case 5:
                show_list_contacts(head);
                break;
            case 6:
                free_list(head);
                dlclose(handle);
                printf("Программа завершена\n");
                return 0;
            default:
                printf("Выберите из предложенного списка:\n\n");
                break;
        }
    }
}

