#include <stdio.h>
#include <time.h>
#include "functions.h"

int main() {
    const char *months[] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };
    int mdays[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    time_t now;
    struct tm *date;
    int month, today, weekday, year, first, day, d;

    time(&now);
    date = localtime(&now);

    month = date -> tm_mon;
    today = date -> tm_mday;
    weekday = date -> tm_wday;
    year = date -> tm_year + 1900;
    mdays[1] = february(year);
    first = the_first(weekday, today);

    printf("%s %d\n", months[month], year);
    printf("Sun Mon Tue Wed Thu Fri Sat\n");

    day = 1;
    while (day < mdays[month]) {
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
    
                if (day > mdays[month]) {
                    break;
                }
            }
        }

        putchar('\n');
    }

    return 0;
}