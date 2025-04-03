#ifndef MAIN_H
#define MAIN_H
#include <dlfcn.h>

#include "list.h"

void display_menu();
void print_contact_info(const char *title, const char array[][MAX_LENGHT], int count);
void print_display(const Contact *contact);
void show_list_contacts(ContactNode *head);
void input_name(char *FirstName, char *LastName);
void wrap_input_data_contact(Contact *contact);
void input_data_contact(const char *title, char *data);
void input_array_contact_info(const char *title, char array[][MAX_LENGHT], int max_count);
void edit_contact(ContactNode *node);
#endif