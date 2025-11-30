#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void strupper(char *s) {
    while (*s) {
        if (*s >= 'a' && *s <= 'z') {
            *s &= 0xdf;
        }

        s++;
    }
}

void strlower(char *s) {
    while (*s) {
        if (*s >= 'A' && *s <= 'Z') {
            *s += 32;
        }

        s++;
    }
}

void strcaps(char *s) {
    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        if ((s[i - 1] == ' ' || i == 0) && ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))) {
            s[i] &= 0xdf;
        }
    }
}

char *strrev(char *s) {
    int len, i;
    char *reversed;

    len = 0;
    while (*s) {
        len++;
        s++;
    }

    reversed = malloc(sizeof(char) * len);

    if (reversed == NULL) {
        fprintf(stderr, "Unable to allocate memory\n");
        exit(1);
    }

    s--;
    i = 0;
    while (len) {
        *(reversed + i) = *s;
        i++;
        len--;
        s--;
    }

    *(reversed + i) = '\0';

    return reversed;
}

int main() {
    char string[] = "Random STRING sample 123#@$";

    printf("Original string: %s\n", string);

    strupper(string);

    printf("Uppercase string: %s\n", string);

    strlower(string);

    printf("Lowercase string: %s\n", string);

    char new_string[] = "this is a sample string";

    strcaps(new_string);

    printf("Capitalized: %s\n", new_string);

    char new_string2[] = "A string dwelling in memory";
    char *reversed_string;

    reversed_string = strrev(new_string2);

    printf("Before: %s\n", new_string2);
    printf("After: %s\n", reversed_string);

    
    return 0;
}