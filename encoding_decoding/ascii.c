#include <stdio.h>

int main() {
    int i;

    printf("Control codes:\n");
    printf("--------------\n");
    printf("Dec\tHex\tChar\n");
    printf("--------------\n");

    for (i = 0; i < 32; i++) {
        printf("%d\t%02x\t%c\n", i, i, i);
    }

    printf("--------------\n");
    printf("Shift keys:\n");
    printf("--------------\n");
    printf("Dec\tHex\tChar\n");
    printf("--------------\n");

    for (i = 32; i < 64; i++) {
        printf("%d\t%02x\t%c\n", i, i, i);
    }

    printf("--------------\n");
    printf("Uppercase and symbols:\n");
    printf("--------------\n");
    printf("Dec\tHex\tChar\n");
    printf("--------------\n");

    for (i = 64; i < 96; i++) {
        printf("%d\t%02x\t%c\n", i, i, i);
    }

    printf("--------------\n");
    printf("Lowercase and symbols:\n");
    printf("--------------\n");
    printf("Dec\tHex\tChar\n");
    printf("--------------\n");

    for (i = 96; i < 128; i++) {
        printf("%d\t%02x\t%c\n", i, i, i);
    }

    return 0;
}