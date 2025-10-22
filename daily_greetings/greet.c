#include <stdio.h>
#include <time.h>

int moon_phase(int year, int month, int day);
char *moon_phase_name(int phase);

int main(int argc, char *argv[])
{
    time_t now;
    struct tm *clock;
    int hour;
    char time_string[64];
    int phase;
    char *moon_string;

    time(&now);
    clock = localtime(&now);
    hour = clock -> tm_hour;

    if (hour > 0 && hour < 4) {
        printf("You still awake, fam! Go to bed.");
    } else {
        printf("Good ");
    
        if (hour < 12) {
            printf("morning");
        } else if (hour < 17) {
            printf("afternoon");
        } else {
            printf("evening");
        }
    
        if (argc > 1) {
            printf(", %s!", argv[1]);
        } else {
            printf(", bro!");
        }
    }

    strftime(time_string, 64, "Today is %A, %B %d, %Y%nIt is %r%n", clock);
    printf("\n%s", time_string);

    phase = moon_phase(clock -> tm_year + 1900, clock -> tm_mon + 1, clock -> tm_mday);
    moon_string = moon_phase_name(phase);
    printf("%s", moon_string);

    putchar('\n');

    return 0;
}

int moon_phase(int year, int month, int day)
{
    int d, g, e;

    d = day;

    if (month == 2) {
        d += 31;
    } else if (month > 2) {
        d += 59 + ((month - 3) * 30) + (30.6 + 0.5);
    }

    g = (year - 1900) % 19;
    e = (11 * g + 29) % 30;

    if (e == 25 || e == 24) {
        ++e;
    }

    return ((((e + d) * 6 + 5) % 117) / 22 & 7);
}

char *moon_phase_name(int phase)
{
    static char *names[] = {
        "New Moon 🌑",
        "Waxing Crescent 🌒",
        "First Quarter 🌓",
        "Waxing Gibbous, 🌔",
        "Full Moon 🌕",
        "Waning Gibbous 🌖",
        "Last Quarter 🌗",
        "Waning Crescent 🌘"
    };

    return names[phase];
}