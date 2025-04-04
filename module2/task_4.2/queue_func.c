#include "main.h"

Node* head = NULL;

Node *create_node(int data, int priority){
    Node *new_node = (Node *)malloc(sizeof(Node));
    if(!new_node){
        printf("Ошибка выделения памяти\n");
        exit(1);
    }
    new_node->data = data;
    new_node->priority = priority;
    new_node->next = NULL;
    
    return new_node;
}


void enqueue(int data, int priority){
    Node * new_node = create_node(data, priority);

    if (head == NULL || priority > head->priority){
        new_node->next = head;
        head = new_node;
    } else {
        Node *current = head;
        while (current->next != NULL && current->next->priority >= priority){
            current = current->next;               
        }

        new_node->next = current->next;
        current->next = new_node;

    }
}

void print_queue(){
    Node * current = head;
    if (current == NULL){
        printf("очередь пуста\n");
        return;
    }
    printf("Значение [приоритет]\n");
    while(current != NULL){
        printf("%d [%d] --> ", current->data, current->priority);
        current = current->next;
    }
    printf("NULL\n\n");
}

int dequeue_priority(int priority){
    if (head == NULL){
        printf("Очередь пустат");
        return -1;
    }

    Node *current = head;
    Node *prev = NULL;

    while(current != NULL && current->priority != priority){
        prev = current;
        current = current->next;
    }

    if (current == NULL){
        printf("Элемент с приоритетом %d не найден\n", priority);
        return -1;
    }

    if (prev == NULL){
        head = current->next;
    } else {
        prev->next = current->next;
    }

    int data = current->data;
    free(current);

    return data;
}

int dequeue_min_priority(int priority){
    if (head == NULL){
        printf("Очередь пустат");
        return -1;
    }

    Node *current = head;
    Node *prev = NULL;

    while(current != NULL && current->priority > priority){
        prev = current;
        current = current->next;
    }

    if (current == NULL){
        printf("Элемент с приоритетом больше %d не найден\n", priority);
        return -1;
    }

    if (prev == NULL){
        head = current->next;
    } else {
        prev->next = current->next;
    }

    int data = current->data;
    free(current);

    return data;
}

int dequeue_first(){
    if(head == NULL){
        printf("Очередь пуста\n");
        return -1;
    }

    Node *current = head;
    int data = current->data;
    head = current->next;
    free(current);

    return data;
}