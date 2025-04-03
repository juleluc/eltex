#ifndef MAIN_H
#define MAIN_H

#include "list.h"

void display_menu();
void print_contact_info(const char *title, const char array[][MAX_LENGHT], int count);
void print_display(const Contact *contact);
void show_list_contacts(ContactNode *head);
void input_name(char *FirstName, char *LastName);

#endif