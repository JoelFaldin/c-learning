#include <stdio.h>
#include <string.h>

int strindex(char string[], char value);

int main()
{
    char str[] = "test";
    char c = 't';

    printf("Last index of %c in %s is: %d", c, str, strindex(str, c));

    return 0;
}

// strindex: return the index of the rightmost occurrence of t (searched value) in s (string):
int strindex(char s[], char t)
{
    int index, i;
    index = -1;

    for (i = 0; i < strlen(s); i++) {
        if (s[i] == t) {
            index = i;
        }
    }

    return index;
}