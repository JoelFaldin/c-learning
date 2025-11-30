#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int strsplit(char *org, int offset, char **s1, char **s2) {
    int len;

    len = strlen(org);

    if (offset > len) {
        return 0;
    }

    *s1 = malloc(sizeof(char) * offset + 1);
    *s2 = malloc(sizeof(char) * len - offset + 1);

    if (s1 == NULL || s2 == NULL) {
        fprintf(stderr, "Memory allocation error");
        return 0;
    }

    strncpy(*s1, org, offset);
    strncpy(*s2, org + offset, len - offset);

    return 1;
}

int main() {
    char original[] = "String to split\0";
    int offset = 7;
    char *s1, *s2;

    int s = strsplit(original, offset, &s1, &s2);

    printf("%d\n", s);
    printf("%s\n", s1);
    printf("%s\n", s2);

    free(s1);
    free(s2);

    return 0;
}
