#include <stdio.h>
#include <time.h>

struct holiday {
    int month;
    int day;
    char *name;
};

int is_holiday(struct tm *d) {
    if (d -> tm_mon == 0 && d -> tm_mday == 1) {
        return 1;
    }

    if (d -> tm_mon == 5 && d -> tm_mday == 19) {
        return 1;
    }

    if (d -> tm_mon == 6 && d -> tm_mday == 4) {
        return 1;
    }

    if (d -> tm_mon == 10 && d -> tm_mday == 11) {
        return 1;
    }

    if (d -> tm_mon == 11 && d -> tm_mday == 25) {
        return 1;
    }

    return 0;
}

int main() {
    time_t now;
    struct tm *today;
    int is_h;

    now = time(NULL);
    today = localtime(&now);

    mktime(today);

    printf("Today is %02d/%02d/%04d", today -> tm_mday, today -> tm_mon + 1, today -> tm_year + 1900);

    is_h = is_holiday(today);

    if (is_h == 0) {
        printf(", not a holiday\n");
    } else {
        printf(", a holiday! :D");
    }

    return 0;
}
