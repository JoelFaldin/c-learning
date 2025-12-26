#include <stdio.h>
#include "functions.h"

int main() {
    const char *month[] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December",
    };
    const char *weekday[] = {
        "Sunday", "Monday", "Tuesday", "Wednesday",
        "Thursday", "Friday", "Saturday",
    };

    int mdays[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    enum { SU, MO, TU, WE, TH, FR, SA };
    int start_day, dom, doy, year, m;

    struct holiday date;
    int r;

    start_day = SA;
    doy = 1;
    year = 2022;

    for (m = 0; m < 12; m++) {
        for (dom = 1; dom <= mdays[m]; dom++) {
            date.day = dom;
            date.month = m;
            date.wday = (doy + start_day - 1) % 7;
            date.year = year;

            printf("%s, %s %d, %d", weekday[(doy + start_day - 1) % 7], month[m], dom, year);
            doy++;

            r = is_holiday(&date);
            if (r == 0) {
                printf(", not a holiday\n");
            } else if (r == 1) {
                printf(", %s!\n", date.name);
            } else if (r == 2) {
                printf(", %s observed\n", weekday[date.wday]);
            }
        }
    }

    return 0;
}