#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;             
    int priority;          
    struct Node* next;      
} Node;

extern Node *head;

void display_menu();

Node *create_node(int data, int priority);
void enqueue(int data, int priority);
void print_queue();
int dequeue_priority(int priority);
int dequeue_min_priority(int priority);
int dequeue_first();


#endif