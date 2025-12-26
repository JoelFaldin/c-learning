#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int day_of_the_week(int m, int d, int y) {
    int t[] = {
        0, 3, 2, 5, 0, 3,
        5, 1, 4, 6, 2, 4
    };
    int r;

    y -= m < 2;
    r = (y + y / 4 - y / 100 + y / 400 + t[m] + d) % 7;

    return r;
}

int main(int argc, char *argv[]) {
    const char *weekday[] = {
        "Sunday", "Monday", "Tuesday", "Wednesday",
        "Thursday", "Friday", "Saturday", "Sunday"
    };
    const char *month[] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August", "September",
        "October", "November", "December"
    };
    time_t now;
    struct tm *date;

    if (argc < 2) {
        time(&now);
        date = localtime(&now);
    
        printf("Today is %s %d, %d, a %s\n",
            month[date -> tm_mon],
            date -> tm_mday,
            date -> tm_year + 1900,
            weekday[day_of_the_week(date -> tm_mon, date -> tm_mday, date -> tm_year + 1900)]
        );
    
        return 0;
    } else if (argc < 4) {
        printf("Not enough arguments provided!\n");
        return 1;
    } else {
        int month_input, day, year;
        char *endptr;

        month_input = strtol(argv[1], &endptr, 10);
        day = strtol(argv[2], &endptr, 10);
        year = strtol(argv[3], &endptr, 10);

        date = localtime(&now);
        date -> tm_mon = month_input;
        date -> tm_mday = day;
        date -> tm_year = year;

        printf("The day %s %d, %d is a %s\n",
            month[date -> tm_mon],
            date -> tm_mday,
            date -> tm_year,
            weekday[day_of_the_week(date -> tm_mon, date -> tm_mday, date -> tm_year)]
        );
    }

    return 0;
}