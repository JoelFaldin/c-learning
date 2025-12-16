#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"

void center(char *text, int width) {
    int len, x;
    len = strlen(text);

    for (x = 0; x < width; x++) {
        printf(" ");
    }

    printf("%s", text);

    for (x = 0; x < width; x++) {
        printf(" ");
    }

    putchar('\n');
}

int main(int argc, char *argv[]) {
    const char *months[] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };
    int mdays[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    time_t now;
    struct tm *date;
    int month, today, weekday, year, first, day, d;
    char buffer[50];

    if (argc == 4) {
        char *endptr;

        month = strtol(argv[1], &endptr, 10) - 1;
        today = strtol(argv[2], &endptr, 10);
        year = strtol(argv[3], &endptr, 10);
        weekday = day_of_the_week(month, today, year);

        mdays[1] = february(year);
        first = the_first(weekday, today);
    } else {
        time(&now);
        date = localtime(&now);
    
        month = date -> tm_mon;
        today = date -> tm_mday;
        weekday = date -> tm_wday;
        year = date -> tm_year + 1900;
        mdays[1] = february(year);
        first = the_first(weekday, today);
    }

    sprintf(buffer, "%s %d", months[month], year);

    center(buffer, 7);
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