#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "functions.h"

#define COLUMNS 3

#define BOLD 1
#define BLACK 0
#define CYAN 6
#define WHITE 7
#define FG 30
#define BG 40

void color_output(int d) {
    if (d % 2) {
        printf("\x1b[%d;m%2d", FG + WHITE, d);
    } else {
        printf("\x1b[%d;m%2d", FG + CYAN, d);
    }
}

int main(int argc, char *argv[]) {
    const char *months[] = {
        "Jan", "Feb", "March", "April",
        "May", "June", "July", "Aug",
        "Sep", "Oct", "Nov", "Dec"
    };
    int mdays[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    struct tm date;

    int month, weekday, year, day, dow, c, dotm[12], week;
    const int output_width = 15;
    char title[output_width];

    if (argc == 2) {
        char *endptr;

        date.tm_year = strtol(argv[1], &endptr, 10) - 1900;
    } else {
        date.tm_year = 2025 - 1900;
    }

    date.tm_mon = 0;
    date.tm_mday = 1;
    date.tm_hour = 0;
    date.tm_min = 0;
    date.tm_sec = 0;

    putenv("TZ=GMT");
    tzset();
    mktime(&date);

    weekday = date.tm_wday;
    year = date.tm_year + 1900 + 1;
    mdays[1] = february(year);

    dotm[0] = weekday;
    for (month = 1; month < 12; month++) {
        dotm[month] = (mdays[month - 1] + dotm[month - 1]) % 7;
    }

    dow = 0;
    for (month = 0; month < 12; month += COLUMNS) {
        for (c = 0; c < COLUMNS; c++) {
            sprintf(title, "%s %d", months[month + c], year);
            center(title, output_width);
            printf("  ");
        }
        
        putchar('\n');
        
        for (c = 0; c < COLUMNS; c++) {
            printf("\x1b[%dm%s", BOLD, "Su");
            printf("\x1b[0m%s", "Mo");
            printf("\x1b[%dm%s", BOLD, "Tu");
            printf("\x1b[0m%s", "We");
            printf("\x1b[%dm%s", BOLD, "Th");
            printf("\x1b[0m%s", "Fi");
            printf("\x1b[%dm%s", BOLD, "Sa");
            printf("\x1b[0m  ");
        }

        putchar('\n');

        // First week loop:
        for (c = 0; c < COLUMNS; c++) {
            day = 1;
            for (dow = 0; dow < 7; dow++) {
                if (dow < dotm[month + c]) {
                    printf("  ");
                } else if (day <= mdays[month + c]) {
                    color_output(day);
                    day++;
                } else {
                    printf("  ");
                }
            }

            printf("  ");
            dotm[month + c] = day;
        }

        putchar('\n');

        for (week = 1; week < 6; week++) {
            for (c = 0; c < COLUMNS; c++) {
                day = dotm[month + c];
                for (dow = 0; dow < 7; dow++) {
                    if (day <= mdays[month + c]) {
                        color_output(day);
                    } else {
                        printf("  ");
                    }

                    day++;
                }

                printf("  ");
                dotm[month + c] = day;
            }

            putchar('\n');
        }

        putchar('\n');
    }

    return 0;
}