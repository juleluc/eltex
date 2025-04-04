#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

void display_rights(int num);
void menu();

int convert_char_to_bits(const char *ch);
void convert_num_to_char(mode_t num, char *rights);
void print_bit(int bits);
int modify_rights(int current_bits, const char *command);

#endif