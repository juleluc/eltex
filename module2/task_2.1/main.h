#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>

#define COUNT_VALUE 3
#define MAX_LENGHT 20
#define MAX_CONTACT 50

typedef struct ContactInfo
{
    char phone_number[COUNT_VALUE][MAX_LENGHT];
    char emails[COUNT_VALUE][MAX_LENGHT];
    char social_link[COUNT_VALUE][MAX_LENGHT];
    char mesenger_profiles[COUNT_VALUE][MAX_LENGHT];

} ContactInfo;

typedef struct Job
{
    char company[MAX_LENGHT];
    char position[MAX_LENGHT];
} Job;

typedef struct Person
{
    char FirstName[MAX_LENGHT];
    char LastName[MAX_LENGHT];

} Person;

typedef struct Contact
{
    Person name;
    Job job_place;
    ContactInfo contact_info;
} Contact;

void choice();
void add_contact(Contact *contact, int *number);
void delete_contact(Contact *contact, int *number_contact);
int show_list_contacts(Contact *contact, int number_contact);
void edit_contact(Contact *contact, int number_contact);
void find_contact(Contact *contact, int number_contact);

#endif