#include <stdio.h>

int tohex(char c);

int main() {
    while (1) {
        char ch = getchar();

        if (ch == EOF) break;

        int a = tohex(ch);

        if (a < 0) break;

        a <<= 4;
        ch = getchar();

        if (ch == EOF) break;

        char b = tohex(ch);

        if (b < 0) break;

        putchar(a + b);
    }

    return 0;
}

int tohex(char c) {
    if (c >= '0' && c <= '9') {
        return (c - '0');
    }

    if (c >= 'A' && c <= 'F') {
        return (c - 'A' + 0xA);
    }

    return -1;
}

