#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>

#define COUNT_VALUE 3
#define MAX_LENGHT 20
#define MAX_CONTACT 50

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

void display_menu();
void print_contact_info(const char *title, const char array[][MAX_LENGHT], int count);
void print_display(const Contact *contact);
int show_list_contacts(Contact *contacts, int number_contacts);

void input_data_contact(const char *title, char *data);
void input_array_contact_info(const char *title, char array[][MAX_LENGHT], int max_count);
void add_contact(Contact *contacts, int *number);
void delete_contact(Contact *contacts, int *number_contacts);
void edit_contact(Contact *contacts, int number_contacts);
void find_contact(Contact *contacts, int number_contacts);

#endif