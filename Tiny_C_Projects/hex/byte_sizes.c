#include <stdio.h>
#include <math.h>

int main() {
    unsigned long byte_char = sizeof(char) * 8;
    printf("%11s %2lu bits %21.f\n", "Byte", byte_char, pow(2, byte_char));

    unsigned long byte_short = sizeof(short) * 8;
    printf("%11s %2lu bits %21.f\n", "Byte", byte_short, pow(2, byte_short));

    unsigned long byte_int = sizeof(int) * 8;
    printf("%11s %2lu bits %21.f\n", "Byte", byte_int, pow(2, byte_int));

    unsigned long byte_long = sizeof(long) * 8;
    printf("%11s %2lu bits %21.f\n", "Byte", byte_long, pow(2, byte_long));

    return 0;
}