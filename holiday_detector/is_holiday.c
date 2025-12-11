#include <stdio.h>
#include <time.h>
#include <math.h>

#define FRIDAY 5
#define MONDAY 1

#define FRIDAY 5
#define THURSDAY 4
#define FIRST_WEEK h -> day < 8
#define SECOND_WEEK h -> day > 7 && h -> day < 15
#define THIRD_WEEK h -> day > 14 && h -> day < 22
#define FOURTH_WEEK h -> day > 21 && h -> day < 29
#define LAST_WEEK h -> day > 24 && h -> day < 32

struct holiday {
    int month;
    int day;
    int year;
    int wday;
    char *name;
};

int easter(struct holiday *hday) {
    int Y, a, c, e, h, k, L;
    double b, d, f, g, i, m, month, day;

    Y = hday -> year;
    a = Y % 19;
    b = floor(Y / 100);
    c = Y % 100;
    d = floor(b / 4);
    e = (int)b % 4;
    f = floor((b + 8) / 25);
    g = floor((b - f + 1) / 3);
    h = (19 * a + (int)b - (int)d - (int)g + 15) % 30;
    i = floor(c / 4);
    k = c % 4;
    L = (32 + 2 * e + 2 * (int)i - h - k) % 7;
    m = floor((a + 11 * h + 22 * L) / 451);

    month = floor((h + L - 7 * m + 114) / 31) - 1;
    day = ((h + L - 7 * (int)m + 114) % 31) + 1;

    if (hday -> month == month && hday -> day == day) {
        return 1;
    } else {
        return 0;
    }
}

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
        "Martin Luther King Day",
        "Presidents Day",
        "Memorial Day",
        "Juneteenth",
        "Independence Day",
        "Labor Day",
        "Columbus Day",
        "Veterans Day",
        "Thanksgiving",
        "Christmas"
    };
    // printf("Day: %d, month: %d\n", h -> day, h -> month);

    int r = 0;

    if (h -> month == 11 && h -> day == 31 && h -> wday == FRIDAY) {
        h -> name = n[0];
        return 2;
    }
    if (h -> month == 0 && h -> day == 1) {
        h -> name = n[0];
        return 1;
    }
    if (h -> month == 0 && h -> day == 2 && h -> wday == MONDAY) {
        h -> name = n[0];
        return 2;
    }

    if (h -> month == 0 && h -> wday == MONDAY) {
        if (THIRD_WEEK) {
            h -> name = n[1];
            return 1;
        }
    }

    if (h -> month == 1 && h -> wday == MONDAY) {
        if (THIRD_WEEK) {
            h -> name = n[2];
            return 1;
        }
    }

    if (h -> month == 4 && h -> wday == MONDAY) {
        if (LAST_WEEK) {
            h -> name = n[3];
            return 1;
        }
    }

    if (h -> month == 5) {
        r = weekend(19, h -> day, h -> wday);
        h -> name = n[4];
        return r;
    }

    if (h -> month == 6) {
        r = weekend(4, h -> day, h -> wday);
        h -> name = n[5];
        return r;
    }

    if (h -> month == 8 && h -> wday == MONDAY) {
        if (FIRST_WEEK) {
            h -> name = n[6];
            return 1;
        }
    }
    if (h -> month == 9 && h -> wday == MONDAY) {
        if (SECOND_WEEK) {
            h -> name = n[7];
            return 1;
        }
    }

    if (h -> month == 10) {
        if (h -> wday == THURSDAY && FOURTH_WEEK) {
            h -> name = n[9];
            return 1;
        }

        r = weekend(11, h -> day, h -> wday);
        h -> name = n[8];
        return r;
    }

    if (h -> month == 10 && h -> wday == THURSDAY) {
        if (FOURTH_WEEK) {
            h -> name = n[9];
            return 1;
        }
    }

    if (h -> month == 11) {
        r = weekend(25, h -> day, h -> wday);
        h -> name = n[10];
        return r;
    }

    r = easter(h);
    if (r == 1) {
        h -> name = n[10];
        return r;
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
    date.year = today -> tm_year + 1900;

    // printf("Today is %02d/%02d/%04d", today -> tm_mday, today -> tm_mon + 1, today -> tm_year + 1900);
    printf("Today is %02d/%02d/%04d", date.day, date.month, date.year);

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
