#include <stdio.h>

int main() {
    int ch;

    while ((ch = getchar()) != EOF) {
        printf("%02X\n", ch);
    }

    return 0;
}