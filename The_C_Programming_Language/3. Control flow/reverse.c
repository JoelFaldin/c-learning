#include <stdio.h>
#include <string.h>

void reverse(char s[]);

int main()
{
    char str[] = "test bro";
    reverse(str);
    printf("%s\n", str);

    char str2[] = "hello";
    reverse(str2);
    printf("%s\n", str2);

    char str3[] = "abc";
    reverse(str3);
    printf("%s\n", str3);

    return 0;
}

void reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}