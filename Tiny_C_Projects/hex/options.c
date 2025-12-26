#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int r, opterr, alpha, bravo, charlie;

    alpha = 0;
    bravo = 0;
    charlie = 0;

    opterr = 0;
    while ((r = getopt(argc, argv, "abc")) != -1) {
        switch (r) {
        case 'a':
            alpha = 1;
            break;
        case 'b':
            bravo = 1;
            break;
        case 'c':
            charlie = 1;
            break;
        case '?':
            printf("Switch '%c' invalid.\n", r);
            break;
        default:
            puts("Unknown option");
            break;
        }
    }

    if (alpha) {
        puts("alpha option set");
    }

    if (bravo) {
        puts("bravo option set");
    }

    if (charlie) {
        puts("charlie option set");
    }

    if (alpha + bravo + charlie == 0) {
        puts("No options set.");
    }

    return 0;
}