#include <stdio.h>

int main()
{
    // Automatic conversion:
    char c = 100;
    short s = 200;
    int result = c + s;

    printf("Result = %d\n", result);

    // Explicit cast:
    double pi = 3.14159;
    int x = (int) pi;
    printf("pi as int = %d\n", x);

    // Divisions:
    int a = 5, b = 2;
    printf("Int division = %d\n", a / b);
    printf("Float division = %f\n", (double) a / b);

    return 0;
}