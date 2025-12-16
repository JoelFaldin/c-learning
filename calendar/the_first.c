#include <stdio.h>
#include <time.h>

int the_first(int wday, int mday) {
    int first;

    first = wday - (mday % 7) + 1;

    if (first < 0) {
        first += 7;
    }

    return first;
}

int main() {
    const char *weekday[] = {
        "Sunday", "Monday", "Tuesday", "Wednesday",
        "Thursday", "Friday", "Saturday"
    };
    time_t now;
    struct tm *date;
    int first;

    time(&now);
    date = localtime(&now);

    first = the_first(date -> tm_wday, date -> tm_mday);

    printf("The first day of this month was on a %s\n", weekday[first]);

    return 0;
}