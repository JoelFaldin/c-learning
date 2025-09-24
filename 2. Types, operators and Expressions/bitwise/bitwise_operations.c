#include <stdio.h>

int main()
{
    unsigned char a = 6;                        // 00000110
    unsigned char b = 3;                        // 00000011

    printf("a & b = %d\n", a & b);              // 00000010
    printf("a | b = %d\n", a | b);              // 00000111
    printf("a ^ b = %d\n", a ^ b);              // 00000101

    printf("~a = %d\n", (unsigned char) ~a);    // 11111001
    printf("a << 1 = %d\n", a << 1);            // 00001100
    printf("a >> 1 = %d\n", a >> 1);            // 00000011

    return 0;
}