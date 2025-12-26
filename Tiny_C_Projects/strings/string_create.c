#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct string {
    char *value;
    int length;
};

int string_create(struct string *s, char *v) {
    if (s == NULL) {
        return 1;
    }

    s -> length = strlen(v);

    s -> value = malloc((s -> length + 1) * sizeof(char));

    if (s -> value == NULL) {
        return 1;
    }

    strcpy(s -> value, v);

    return 0;
}

void string_destroy(struct string *s) {
    free(s -> value);
    s -> value = NULL;
    s -> length = 0;
}

int main() {
    struct string str1;

    if (string_create(&str1, "dadada") != 0) {
        fprintf(stderr, "string_create failed\n");
        return 1;
    }

    printf("Value: '%s'\n", str1.value);
    printf("Length: %lu\n", str1.length);

    string_destroy(&str1);

    printf("Value: '%s'\n", str1.value);
    printf("Length: %lu\n", str1.length);

    return 0;
}