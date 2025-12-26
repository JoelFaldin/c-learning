#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MIN 0
#define MAX 1

int main() {
    int ch;
    int random;

    while ((ch = getchar()) != EOF) {
        random = rand() % (MAX - MIN + 1) + MIN;

        if (random == 0) {
            putchar(toupper(ch));
            continue;
        } else {
            putchar(tolower(ch));
            continue;
        }
    }

    return 0;
}