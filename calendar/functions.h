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