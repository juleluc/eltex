#include "list.h"

ContactNode *add_contact_sorted(ContactNode *head, Contact new_contact) {
    ContactNode *new_node = (ContactNode *)malloc(sizeof(ContactNode));
    if (!new_node) {
        perror("Ошибка выделения памяти");
        exit(1);
    }
    new_node->data = new_contact;
    new_node->prev = NULL;
    new_node->next = NULL;

    if (head == NULL || strcmp(new_contact.name.FirstName, head->data.name.FirstName) < 0 ||
        (strcmp(new_contact.name.FirstName, head->data.name.FirstName) == 0 &&
         strcmp(new_contact.name.LastName, head->data.name.LastName) < 0)) {
        new_node->next = head;
        if (head != NULL) {
            head->prev = new_node;
        }
        return new_node;
    }

    ContactNode *current = head;
    while (current->next != NULL &&
           (strcmp(new_contact.name.FirstName, current->next->data.name.FirstName) > 0 ||
            (strcmp(new_contact.name.FirstName, current->next->data.name.FirstName) == 0 &&
             strcmp(new_contact.name.LastName, current->next->data.name.LastName) > 0))) {
        current = current->next;
    }

    new_node->next = current->next;
    if (current->next != NULL) {
        current->next->prev = new_node;
    }
    current->next = new_node;
    new_node->prev = current;

    return head;
}

ContactNode *delete_contact(ContactNode *head, const char *FirstName, const char *LastName) {
    ContactNode *current = head;
    while (current != NULL) {
        if (strcmp(current->data.name.FirstName, FirstName) == 0 &&
            strcmp(current->data.name.LastName, LastName) == 0) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                head = current->next;
            }
            if (current->next != NULL) {
                current->next->prev = current->prev;
            }
            free(current);
            return head;
        }
        current = current->next;
    }
    return head;
}

ContactNode *find_contact(ContactNode *head, const char *FirstName, const char *LastName) {
    ContactNode *current = head;
    while (current != NULL) {
        if (strcmp(current->data.name.FirstName, FirstName) == 0 &&
            strcmp(current->data.name.LastName, LastName) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void edit_contact(ContactNode *head, char *FirstName, char *LastName) {
    ContactNode *node = find_contact(head, FirstName, LastName);

    if (node == NULL) {
        printf("Контакт не найден\n");
        return;
    }
    printf("Редактируйте данные контакта:\n");
    wrap_input_data_contact(&node->data);
    printf("Контакт обновлен\n");
}

void free_list(ContactNode *head) {
    ContactNode *current = head;
    while (current != NULL) {
        ContactNode *next = current->next;
        free(current);
        current = next;
    }
}

void wrap_input_data_contact(Contact *contact){
    input_data_contact("Введите Имя", contact->name.FirstName);
    input_data_contact("Введите Фамилию", contact->name.LastName);

    input_data_contact("Введите Место работы (Пропустить: skip)", contact->job_place.company);
    input_data_contact("Введите Должность (Пропустить: skip)", contact->job_place.position);

    input_array_contact_info("Введите Телефон (Пропустить: skip)", contact->contact_info.phone_number, COUNT_VALUE);
    input_array_contact_info("Введите Email (Пропустить: skip)", contact->contact_info.emails, COUNT_VALUE);
    input_array_contact_info("Введите Соцсети (Пропустить: skip)", contact->contact_info.social_link, COUNT_VALUE);
    input_array_contact_info("Введите Мессенджеры (Пропустить: skip)", contact->contact_info.messenger_profiles, COUNT_VALUE);

}

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