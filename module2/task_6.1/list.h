#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    Contact data; 
    struct ContactNode *prev; 
    struct ContactNode *next; 
} ContactNode;


ContactNode *add_contact_sorted(ContactNode *head, Contact new_contact);
ContactNode *delete_contact(ContactNode *head, const char *FirstName, const char *LastName);
ContactNode *find_contact(ContactNode *head, const char *FirstName, const char *LastName);
void edit_contact(ContactNode *head, char *FirstName, char *LastName);
void free_list(ContactNode *head);
void wrap_input_data_contact(Contact *contact);
void input_data_contact(const char *title, char *data);
void input_array_contact_info(const char *title, char array[][MAX_LENGHT], int max_count);

#endif 