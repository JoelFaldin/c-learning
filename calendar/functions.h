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

int the_first(int wday, int mday) {
    int first;

    first = wday - (mday % 7) + 1;

    if (first < 0) {
        first += 7;
    }

    return first;
}

// Format: day_of_the_week(Month [0-11], Day n [1-31], Year)
int day_of_the_week(int m, int d, int y) {
    int t[] = {
        0, 3, 2, 5, 0, 3,
        5, 1, 4, 6, 2, 4
    };
    int r;

    y -= m < 2;
    r = (y + y / 4 - y / 100 + y / 400 + t[m] + d) % 7;

    return r;
}