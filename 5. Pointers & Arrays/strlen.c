#include <stdio.h>

int str_len(char *s)
{
    char *p = s;

    while (*p != '\0') {
        p++;
    }

    return p - s;
}

int main()
{
    char str[] = "test";
    int len = str_len(str);

    printf("%d\n", len);

    return 0;
}