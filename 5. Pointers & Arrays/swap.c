#include <stdio.h>

int swap(int *a, int *b)
{
    int prev = *a;
    *a = *b;
    *b = prev;
}

int main()
{
    int x = 10, y = 20;
    swap(&x, &y);

    printf("x = %d\n", x);
    printf("y = %d\n", y);

    return 0;
}