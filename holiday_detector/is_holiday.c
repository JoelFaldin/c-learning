#include <stdio.h>
#include <time.h>

struct holiday {
    int month;
    int day;
    char *name;
};

int is_holiday(struct holiday *h) {
    char *n[] = {
        "New Years Day",
        "Juneteenth",
        "Independence Day",
        "Veterans Day",
        "Christmas"
    };

    if (h -> month == 0 && h -> day == 1) {
        h -> name = n[0];
        return 1;
    }

    if (h -> month == 5 && h -> day == 19) {
        h -> name = n[1];
        return 1;
    }

    if (h -> month == 6 && h -> day == 4) {
        h -> name = n[2];
        return 1;
    }

    if (h -> month == 10 && h -> day == 11) {
        h -> name = n[3];
        return 1;
    }

    if (h -> month == 11 && h -> day == 25) {
        h -> name = n[4];
        return 1;
    }

    return 0;
}

int main() {
    time_t now;
    struct tm *today;
    struct holiday date;
    int is_h;

    now = time(NULL);
    today = localtime(&now);

    mktime(today);

    date.day = today -> tm_mday;
    date.month = today -> tm_mon + 1;

    // printf("Today is %02d/%02d/%04d", today -> tm_mday, today -> tm_mon + 1, today -> tm_year + 1900);
    printf("Today is %02d/%02d/%04d", date.day, date.month, today -> tm_year + 1900);

    is_h = is_holiday(&date);

    if (is_h == 0) {
        printf(", not a holiday\n");
    } else {
        printf(", %s!\n", date.name);
    }

    return 0;
}
