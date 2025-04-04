#include "main.h"
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Ошибка: %s ip_src mask num_packets\n", argv[0]);
        return 1;
    }

    char* ip_src = argv[1];
    char* mask = argv[2];
    int num_packets = atoi(argv[3]);

    char (*packets)[IP_LENGTH] = malloc(num_packets * sizeof(*packets));
    if (packets == NULL) {
        printf("Ошибка: Не удалось выделить память.\n");
        return 1;
    }

    int count_subnet = 0;

    srand(time(NULL)); 

    generat_ip(num_packets, packets, &count_subnet, ip_src, mask);

    printf("\nСтатистика:\n");
    printf("Пакеты для своей подсети: %d (%.2f %%)\n", count_subnet, (float)count_subnet / num_packets * 100);
    printf("Пакеты для других сетей: %d (%.2f %%)\n", num_packets - count_subnet, (float)(num_packets - count_subnet) / num_packets * 100);
    free(packets);
    
    return 0;
}