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

int weekend(int holiday, int mday, int wday);

int easter(struct holiday *hday);

// Returns 0 if the passed date is not a holiday, 1 if is a holiday and 2 if its a holiday and on a monday.
int is_holiday(struct holiday *h);