#include <stdio.h>

int main() {
    char sentence[] = "ASCII is pretty cool";
    char *s;

    s = sentence;
    while(*s) {
        if (*s >= 'A' && *s <= 'Z') {
            putchar(*s | 0x20);
        } else {
            putchar(*s);
        }

        s++;
    }

    printf("\n");

    s = sentence;
    while (*s) {
        if (*s >= 'a' && *s <= 'z') {
            putchar(*s & 0xdf);
        } else {
            putchar(*s);
        }

        s++;
    }

    printf("\n------\n");
    printf("Convert to lowercase: \n");

    char word = 'R';
    char lower = word | 0x20;
    // 0x20 -> 32 en binario

    printf("%c\n", lower);

    printf("Convert to uppercase: \n");

    char word2 = 'f';
    char upper = word2 & ~0x20;

    printf("%c\n", upper);

    return 0;
}
