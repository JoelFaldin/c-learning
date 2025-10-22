#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[])
{
    time_t now;

    time(&now);

    if (argc < 2) {
        printf("Hello, bro!\n");
        printf("It is %ld\n", now);
        printf("%s", ctime(&now));
    } else {
        printf("Hello, %s!\n", argv[1]);
    }

    return 0;
}