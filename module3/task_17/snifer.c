#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <net/ethernet.h>  // Для struct ether_header и ETH_P_ALL
#include <linux/if_packet.h> // Для AF_PACKET

#define PORT 12345
#define MAX_SIZE 65536 // Максимальный размер Ethernet-пакета

int main() {
    int sock_fd;
    char buffer[MAX_SIZE];

    // Создаем RAW-сокет
    if ((sock_fd = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL))) == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    printf("Sniffer started... Waiting for UDP packets on port %d\n", PORT);

    while (1) {
        struct sockaddr saddr;
        socklen_t saddr_len = sizeof(saddr);
        int buflen;

        // Получаем пакет
        buflen = recvfrom(sock_fd, buffer, sizeof(buffer), 0, &saddr, &saddr_len);
        if (buflen < 0) {
            perror("recvfrom failed");
            continue;
        }

        // Ethernet header
        struct ether_header *eth_hdr = (struct ether_header *)buffer;
        if (ntohs(eth_hdr->ether_type) != ETHERTYPE_IP) {
            continue; // Не IP-пакет
        }

        // IP-заголовок
        struct iphdr *ip_header = (struct iphdr *)(buffer + sizeof(struct ether_header));
        if (ip_header->protocol != IPPROTO_UDP)
            continue; // Только UDP

        // UDP-заголовок
        struct udphdr *udp_header = (struct udphdr *)((char *)ip_header + (ip_header->ihl * 4));

        // Проверяем целевой порт
        if (ntohs(udp_header->dest) == PORT) {
            char *data = (char *)udp_header + sizeof(struct udphdr);
            int data_len = ntohs(udp_header->len) - sizeof(struct udphdr);

            printf("\nReceived UDP packet to port %d (%d bytes):\n", PORT, data_len);
            printf("Data: '%.*s'\n", data_len, data); // Выводим как строку

            // Дополнительно: выводим hex-дамп
            printf("Hex dump:\n");
            for (int i = 0; i < data_len; i++) {
                printf("%02X ", (unsigned char)data[i]);
                if ((i + 1) % 16 == 0) printf("\n");
            }
            printf("\n");
        }
    }

    close(sock_fd);
    return 0;
}