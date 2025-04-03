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


void free_list(ContactNode *head) {
    ContactNode *current = head;
    while (current != NULL) {
        ContactNode *next = current->next;
        free(current);
        current = next;
    }
}
