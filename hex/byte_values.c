#include <stdio.h>

int main() {
    unsigned char data[256];
    int b;

    for (b = 0; b < 256; b++) {
        data[b] = b;
    }

    for (b = 0; b < 256; b++) {
        printf(" %02X", data[b]);
        // printf(" %d", data[b]);

        if ((b + 1) % 16 == 0) {
            putchar('\n');
        }

        if ((b + 1) % 8 == 0) {
            putchar(' ');
        }
    }

    return 0;
}