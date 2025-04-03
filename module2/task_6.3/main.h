#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>

void display_menu();
double* get_array_value(int *count);

int addition(int n, double numbers[], double *result);
int division(int n, double numbers[], double *result);
int multiplication(int n, double numbers[], double *result);
int subtraction(int n, double numbers[], double *result);

#endif