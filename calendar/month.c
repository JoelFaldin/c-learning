#include <stdio.h>

int main() {
    int mdays, today, first, day, d;
    mdays = 31;
    today = 16;
    first = 1;

    printf("December 2025\n");
    printf("Sun Mon Tue Wed Thu Fri Sat\n");

    day = 1;
    while (day < mdays) {
        for (d = 0; d < 7; d++) {
            if (d < first && day == 1) {
                printf("    ");
            } else {
                if (day == today) {
                    printf("[%2d]", day);
                } else {
                    printf(" %2d ", day);
                }

                day++;
    
                if (day > mdays) {
                    break;
                }
            }
        }

        putchar('\n');
    }

    return 0;
}