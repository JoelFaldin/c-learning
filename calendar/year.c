#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "functions.h"

int main() {
    const char *months[] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };
    int mdays[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    struct tm date;

    int month, weekday, year, day, dow;
    const int output_width = 27;
    char title[output_width];

    date.tm_year = 2026 - 1900;
    date.tm_mon = 0;
    date.tm_mday = 1;
    date.tm_hour = 0;
    date.tm_min = 0;
    date.tm_sec = 0;

    putenv("TZ=GMT");
    tzset();
    mktime(&date);

    weekday = date.tm_wday;
    year = date.tm_year + 1900;
    mdays[1] = february(year);

    dow = 0;
    for (month = 0; month < 12; month++) {
        sprintf(title, "%s %d", months[month], year);
        center(title, 7);
        printf("Sun Mon Tue Wed Thu Fri Sat\n");

        day = 1;
        while (day <= mdays[month]) {
            if (dow < weekday && day == 1) {
                printf("    ");
                dow++;
            } else {
                printf(" %2d ", day);
                dow++;

                if (dow > 6) {
                    dow = 0;
                    putchar('\n');
                }

                day++;
                if (day > mdays[month]) {
                    break;
                }
            }
        }

        weekday = dow;
        dow = 0;
        printf("\n\n");
    }

    return 0;
}