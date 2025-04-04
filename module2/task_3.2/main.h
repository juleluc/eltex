#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PACKETS 1000
#define IP_LENGTH 16

int check_subnet(char *ip, char *Ip_src, char *mask);
void generat_ip(int num_packets, char packets[][IP_LENGTH], int *count_subnet, char *ip_src, char *mask);
#endif