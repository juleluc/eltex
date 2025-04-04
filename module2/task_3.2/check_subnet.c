#include "main.h"

int check_subnet(char* ip, char* ip_src, char* mask) {
    int ip_octets[4], ip_src_octets[4], mask_octets[4];

    sscanf(ip, "%d.%d.%d.%d", &ip_octets[0], &ip_octets[1], &ip_octets[2], &ip_octets[3]);
    sscanf(ip_src, "%d.%d.%d.%d", &ip_src_octets[0], &ip_src_octets[1], &ip_src_octets[2], &ip_src_octets[3]);
    sscanf(mask, "%d.%d.%d.%d", &mask_octets[0], &mask_octets[1], &mask_octets[2], &mask_octets[3]);

    for (int i = 0; i < 4; i++) {
        if ((ip_octets[i] & mask_octets[i]) != (ip_src_octets[i] & mask_octets[i])) {
            return 0; 
        }
    }
    return 1; 
}