#include <stdio.h>

int main()
{
    int a[5] = {10, 20, 30, 40, 50};
    int *p;

    p = a; // &a[0]

    printf("%d\n", *p);
    printf("%d\n", *(p + 1));
    printf("%d\n", *(p + 2));

    return 0;
}