#include <stdio.h>
#include <string.h>

int trim(char s[]);

int main()
{
    char str[] = "helloo      ";
    printf("%s\n", str);
    printf("%d\n", strlen(str));

    trim(str);

    printf("%s\n", str);
    printf("%d\n", strlen(str));

    char str2[] = "";
    printf("%s\n", str2);
    printf("%d\n", strlen(str2));

    trim(str2);
    printf("%s\n", str2);
    printf("%d\n", strlen(str2));

    return 0;
}

// trim: remove trailing blanks, tabs, newlines:
int trim(char s[])
{
    int n;

    for (n  = strlen(s) - 1; n >= 0; n--) {
        if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n') {
            break;
        }

        s[n + 1] = '\0';
    }

    return n;
}