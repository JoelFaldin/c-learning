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