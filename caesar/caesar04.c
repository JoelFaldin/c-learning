#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    int shift, ch;

    if (argc != 3) {
        printf("You should provide both shift values!\n");
        return 1;
    }

    shift = argv[1][0] - argv[2][0];

    while ((ch = getchar()) != EOF) {
        if (isupper(ch)) {
            ch += shift;

            if (ch > 'Z') ch -= 26;
            if (ch < 'A') ch += 26;

            putchar(ch);
        } else if (islower(ch)) {
            ch += shift;

            if (ch > 'z') ch -= 26;
            if (ch < 'a') ch += 26;

            putchar(ch);
        } else {
            putchar(ch);
        }
    }

    return 0;
}