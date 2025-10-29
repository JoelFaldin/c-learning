#include <stdio.h>

char *bin_string(char a);

int main() {
    char c;

    c = 'A';
    printf("Character: %c\tBinary: %s\n", c, bin_string(c));

    return 0;
}

char *bin_string(char a) {
    static char b[9];
    int i;

    i = 0;
    while (i < 8) {
        b[i] = a&0x80 ? '1' : '0';
        a <<= 1;

        i++;
    }

    b[i] = '\0';

    return b;
}