#include <stdio.h>

int february(int year) {
    if (year % 400 == 0) {
        return 29;
    }
    if (year % 100 == 0) {
        return 28;
    }
    if (year % 4 != 0) {
        return 28;
    }

    return 29;
}

int main() {
    int year, result;
    int finish = 2101;

    for (year = 1584; year < finish; year++) {
        result = february(year);

        if (result == 29) {
            printf("%d\n", year);
        }
    }

    return 0;
}