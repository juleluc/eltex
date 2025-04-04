#include "main.h"

void generat_ip(int num_packets, char packets[][IP_LENGTH], int *count_subnet, char *ip_src, char *mask) {
    for (int i = 0; i < num_packets; i++) {
        sprintf(packets[i], "%d.%d.%d.%d", rand() % 256, rand() % 256, rand() % 256, rand() % 256);

        if (check_subnet(packets[i], ip_src, mask)) {
            printf("Пакет %d: IP %s -> Своя подсеть\n", i + 1, packets[i]);
            (*count_subnet)++;
        } else {
            printf("Пакет %d: IP %s -> Другая сеть\n", i + 1, packets[i]);
        }
    }
}