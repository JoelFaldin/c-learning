#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    const int balls = 69, draw = 5;
    int x, r, count;
    int winners[balls];

    srand((unsigned)time(NULL));

    printf("Drawing %d numbers from %d balls:\n", draw, balls);

    for (x = 0; x < balls; x++) {
        winners[x] = 0;
    }

    for (x = 0; x < draw; x++) {
        do {
            r = rand() % balls;
        } while (winners[r] == 1);
        winners[r] = 1;
    }

    count = 0;
    for (x = 0; x < balls; x++) {
        if (winners[x]) {
            printf("%d", x + 1);
            count++;

            if (count < draw) {
                printf(" - ");
            }
        }
    }

    putchar('\n');

    return 0;
}