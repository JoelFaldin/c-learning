struct holiday {
    int month;
    int day;
    int year;
    int wday;
    char *name;
};

int is_holiday(struct holiday *h);