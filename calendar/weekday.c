#include <stdio.h>
#include <time.h>

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

int main() {
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

    time(&now);
    date = localtime(&now);

    printf("Today is %s %d, %d, a %s\n",
        month[date -> tm_mon],
        date -> tm_mday,
        date -> tm_year + 1900,
        weekday[day_of_the_week(date -> tm_mon, date -> tm_mday, date -> tm_year + 1900)]
    );

    return 0;
}