#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *get_weekday(int num_day) {
    static char *days[] = {
        "sunday", "monday", "tuesday", "wednesday", "thursday",
        "friday", "saturday",
    };

    if (num_day < 1 || num_day > 7) {
        fprintf(stderr, "Invalid day of the week\n");
        exit(1);
    }

    return days[num_day];
}

char *get_month(int num_month) {
    
    static char *months[] = {
        "january", "february", "march",
        "april", "may", "june",
        "july", "august", "september",
        "october", "november", "december"
    };

    if (num_month < 1 || num_month > 12) {
        fprintf(stderr, "Invalid integer month");
        exit(1);
    }

    return months[num_month - 1];
}

int main() {
    time_t now;
    struct tm *today;
    int day, month, year, weekday;

    now  = time(NULL);
    today = localtime(&now);
    
    day = today -> tm_mday;
    month = today -> tm_mon + 1;
    weekday = today -> tm_wday;
    year = today -> tm_year + 1900;

    printf("Today is %s %d, %s, %d\n", get_weekday(weekday), day, get_month(month), year);

    return 0;
}
