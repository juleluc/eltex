#include "main.h"

int convert_char_to_bits(const char *ch) {
    int bits = 0;
    int mask;
    for (int i = 0; i < 9; i++) {
        if (ch[i] != '-') {
            mask = (1 << (8 - i)); 
            bits = bits | mask;
        }
    }
    return bits;
}

void convert_num_to_char(mode_t num, char *rights) {

    rights[0] = (num & S_IRUSR) ? 'r' : '-'; 
    rights[1] = (num & S_IWUSR) ? 'w' : '-'; 
    rights[2] = (num & S_IXUSR) ? 'x' : '-'; 

    rights[3] = (num & S_IRGRP) ? 'r' : '-'; 
    rights[4] = (num & S_IWGRP) ? 'w' : '-'; 
    rights[5] = (num & S_IXGRP) ? 'x' : '-'; 

    rights[6] = (num & S_IROTH) ? 'r' : '-'; 
    rights[7] = (num & S_IWOTH) ? 'w' : '-'; 
    rights[8] = (num & S_IXOTH) ? 'x' : '-'; 

    rights[9] = '\0'; 
}

void print_bit(int bits) {
    printf("Битовое представление: ");
    int bit_buf[9];
    int idx = 0;

    while(bits > 0){
        bit_buf[idx] = bits % 2;
        bits /= 2;
        idx++;
    }
    
    for(int i = idx - 1; i >= 0; i--){
        printf("%d", bit_buf[i]);
    }
    printf("\n");
}

int modify_rights(int current_bits, const char *command) {

    int new_bits = current_bits;
    const char *symbol = "rwx"; 
    int start, end;

    switch(command[0]){
        case 'u': start = 6; end = 9; break;
        case 'g': start = 3; end = 6; break;
        case 'o': start = 0; end = 3; break;
        case 'a': start = 0; end = 9; break;
        default:
            printf("Некорректная группа: %c\n", command[0]);
            return current_bits;
    }

    for (int i = start; i < end; i++) {
        char right_char = symbol[i % 3];
        if (strchr(&command[2], right_char)) { 
            int bit_position = 8 - i; 
            int mask = 1 << bit_position;
            if (command[1] == '+') {
                new_bits |= mask;
            } else if (command[1] == '-') {
                new_bits &= ~mask;
            }
        }
    }

    return new_bits;
}