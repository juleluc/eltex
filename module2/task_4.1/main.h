#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define COUNT_VALUE 3
#define MAX_LENGHT 20

typedef struct ContactInfo {
    char phone_number[COUNT_VALUE][MAX_LENGHT];
    char emails[COUNT_VALUE][MAX_LENGHT];
    char social_link[COUNT_VALUE][MAX_LENGHT];
    char messenger_profiles[COUNT_VALUE][MAX_LENGHT];
} ContactInfo;

typedef struct Job {
    char company[MAX_LENGHT];
    char position[MAX_LENGHT];
} Job;

typedef struct Person {
    char FirstName[MAX_LENGHT];
    char LastName[MAX_LENGHT];
} Person;

typedef struct Contact {
    Person name;
    Job job_place;
    ContactInfo contact_info;
} Contact;

typedef struct ContactNode {
    Contact data; // Данные контакта
    struct ContactNode *prev; // Указатель на предыдущий элемент
    struct ContactNode *next; // Указатель на следующий элемент
} ContactNode;

void display_menu();
void print_contact_info(const char *title, const char array[][MAX_LENGHT], int count);
void print_display(const Contact *contact);
void show_list_contacts(ContactNode *head);
void wrap_input_data_contact(Contact *contact);
void input_name(char *FirstName, char *LastName);

void input_data_contact(const char *title, char *data);
void input_array_contact_info(const char *title, char array[][MAX_LENGHT], int max_count);
ContactNode *add_contact_sorted(ContactNode *head, Contact new_contact);
ContactNode *delete_contact(ContactNode *head, char *FirstName, char *LastName);
void edit_contact(ContactNode *head, char *FirstName, char *LastName);
ContactNode *find_contact(ContactNode *head, char *FirstName, char *LastName);
void free_list(ContactNode *head);

#endif