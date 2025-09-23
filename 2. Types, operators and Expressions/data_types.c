#include <stdio.h>

// show type sizes:
int main()
{
    printf("char: %zu byte\n", sizeof(char));
    printf("int: %zu bytes\n", sizeof(int));

    printf("short: %zu bytes\n", sizeof(short));
    printf("long: %zu bytes\n", sizeof(long));
    printf("long long: %zu bytes\n", sizeof(long long));

    printf("float: %zu bytes\n", sizeof(float));
    printf("double: %zu bytes\n", sizeof(double));
    printf("long double: %zu bytes\n", sizeof(long double));

    return 0;
}