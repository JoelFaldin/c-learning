#include <stdio.h>

// format specifiers:
// %d, %u, %x, %o, %c, %f, %s

int main()
{
    unsigned int u = 123U;
    long l = 123L;
    float f = 3.14f;
    double d = 3.14;
    long double ld = 3.14L;

    printf("u = %u\n", u);
    printf("l = %ld\n", l);
    printf("f = %f\n", f);
    printf("d = %lf\n", d);
    printf("ld = %Lf\n", ld);

    return 0;
}