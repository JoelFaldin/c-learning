#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[])
{
    time_t now;
    struct tm *clock;
    int hour;
    char time_string[64];

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

    putchar('\n');

    return 0;
}