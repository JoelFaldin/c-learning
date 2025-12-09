#include <stdio.h>
#include <time.h>

#define FRIDAY 5
#define MONDAY 1

struct holiday {
    int month;
    int day;
    int wday;
    char *name;
};

int weekend(int holiday, int mday, int wday) {
    if (mday > holiday - 2 && mday < holiday + 2) {
        if (mday == holiday - 1 && wday == FRIDAY) {
            return 2;
        }

        if (mday == holiday + 1 && wday == MONDAY) {
            return 2;
        }

        if (mday == holiday) {
            return 1;
        }
    }

    return 0;
}

int is_holiday(struct holiday *h) {
    char *n[] = {
        "New Years Day",
        "Juneteenth",
        "Independence Day",
        "Veterans Day",
        "Christmas"
    };
    // printf("Day: %d, month: %d\n", h -> day, h -> month);

    int w = 0;
    switch (h -> month) {
    case 1:
        w = weekend(1, h -> day, h -> wday);
        if (w) {
            h -> name = n[0];
            return w;
        }
        break;
    case 6:
        w = weekend(19, h -> day, h -> wday);
        if (w) {
            h -> name = n[1];
            return w;
        }
        break;
    case 7:
        w = weekend(4, h -> day, h -> wday);
        if (w) {
            h -> name = n[2];
            return 2;
        }
        break;
    case 11:
        w = weekend(11, h -> day, h -> wday);
        if (w) {
            h -> name = n[3];
            return w;
        }
        break;
    case 12:
        w = weekend(25, h -> day, h -> wday);
        if (w) {
            h -> name = n[4];
            return w;
        }
        break;
    default:
        break;
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
    date.wday = today -> tm_wday;

    // printf("Today is %02d/%02d/%04d", today -> tm_mday, today -> tm_mon + 1, today -> tm_year + 1900);
    printf("Today is %02d/%02d/%04d", date.day, date.month, today -> tm_year + 1900);

    is_h = is_holiday(&date);

    if (is_h == 0) {
        printf(", not a holiday\n");
    } else if (is_h == 1) {
        printf(", %s!\n", date.name);
    } else if (is_h == 2) {
        printf(", %s observed\n", date.wday);
    }

    return 0;
}
