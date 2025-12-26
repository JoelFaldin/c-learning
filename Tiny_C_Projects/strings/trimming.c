#include <stdio.h>
#include <stdlib.h>

char *left(char *s, int len) {
    char *buf;
    int x;

    buf = malloc(sizeof(char) * len + 1);

    if (buf == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(1);
    }

    for (x = 0; x < len; x++) {
        if (*(s + x) == '\0') {
            break;
        }

        *(buf + x) = *(s + x);
    }

    *(buf + x) = '\0';

    return buf;
}

char *rigth(char *s, int len) {
    char *buf;
    char *start;
    int x;

    buf = (char *)malloc(sizeof(char) * len + 1);

    if (buf == NULL) {
        fprintf(stderr, "Memory allocation error");
        exit(1);
    }

    // Searching for the end of the string:
    start = s;
    while (*start != '\0') {
        start++;
    }

    start -= len;
    if (start < s) {
        exit(1);
    }

    for (x = 0; x < len; x++) {
        // Copying the resulting string into the new buffer:
        *(buf + x) = *(start + x);
    }

    *(buf + x) = '\0';

    return buf;
}

char *mid(char *s, int offset, int len) {
    char *buf;
    int x;

    buf = (char *)malloc(sizeof(char) * len + 1);
    if (buf == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(1);
    }

    for (x = 0; x < len; x++) {
        *(buf + x) = *(s + offset - 1 + x);
        if (*(buf + x) == '\0') {
            break;
        }
    }

    *(buf + x) = '\0';

    return buf;
}

int main() {
    char string[] = "Slice me, dice me, make julienne fries!";

    char *result;
    result = left(string, 8);

    printf("%s\n", result);
    free(result);

    char *result2;
    result2 = rigth(string, 20);

    printf("%s\n", result2);
    free(result2);

    char *result3;
    result3 = mid(string, 11, 7);

    printf("%s\n", result3);
    free(result3);

    return 0;
}