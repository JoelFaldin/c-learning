#include <stdio.h>

#define RESET "\x1b[0m"
#define BOLD "\x1b[1m"
#define FAINT "\x1b[2m"
#define UNDERLINE "\x1b[4m"
#define BLINK "\x1b[5m"
#define INVERSE "\x1b[7m"

int main() {
    printf("%sBold text%s\n", BOLD, RESET);
    printf("%sFaint text%s\n", FAINT, RESET);
    printf("%sUnderline text%s\n", UNDERLINE, RESET);
    printf("%sBlinking text%s\n", BLINK, RESET);
    printf("%sInverse text%s\n", INVERSE, RESET);

    printf("-------------");
    putchar('\n');

    int f, b;

    for (f = 0; f < 8; f++) {
        for (b = 0; b < 8; b++) {
            printf("\x1b[%d;%dm %d:%d ", f + 30, b + 40, f + 30, b + 40);
        }

        printf("\x1b[0m\n");
    }

    return 0;
}