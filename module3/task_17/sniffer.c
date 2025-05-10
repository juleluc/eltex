#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <sys/socket.h>

#define MAX_SIZE 65536 // максимально допустимый размер пакета IP 64 кБ

int main() {
    int raw_sock;
    char buffer[MAX_SIZE];

    raw_sock = socket(AF_INET, SOCK_RAW, IPPROTO_UDP);
    if (raw_sock < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    printf("Listening for UDP packets...\n");

    while (1) {
        ssize_t packet_len = recvfrom(raw_sock, buffer, MAX_SIZE, 0, NULL, NULL);
        if (packet_len < 0) {
            perror("recvfrom");
            close(raw_sock);
            exit(EXIT_FAILURE);
        }

        struct iphdr *ip = (struct iphdr *)buffer;
        if (ip->protocol != IPPROTO_UDP) {
            continue; 
        }

        struct udphdr *udp = (struct udphdr *)(buffer + (ip->ihl * 4)); // смещаем указатель на начало UDP

        char *data = (char *)(buffer + (ip->ihl * 4) + sizeof(struct udphdr));  // смещаем указатель на начало данных
        int data_len = ntohs(udp->len) - sizeof(struct udphdr);

        if (ntohs(udp->dest) == 12345 || ntohs(udp->source) == 12345) {
            printf("Packet from %s:%d to %s:%d | Data: %s\n", inet_ntoa(*(struct in_addr *)&ip->saddr), ntohs(udp->source),
                inet_ntoa(*(struct in_addr *)&ip->daddr),ntohs(udp->dest), data);
            printf("Hex: ");
            for (int i = 0; i < data_len; i++) {
                printf("%02x ", (unsigned char)data[i]);
            }
            printf("\n");
        }
    }

    close(raw_sock);
    return 0;
}
