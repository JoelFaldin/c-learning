# Calendar

A series of programs/exercises/functions that outputs days of the week and other useful utilities.

1. Get weekday from current date:

```
gcc ./calendar/weekday.c
./a.out
```

Result: `Today is [month] [day number], [year], a [day of the week]`. It prints the current date.

2. Get weekday from an specified date:

```
gcc ./calendar/weekday.c
./a.out 12 31 2025
```

Function format: `.a/.out [month] [day] [year]`
Result: `The day [month] [day number], [year] is a [day of the week]`

3. Print leap years

```
gcc ./calendar/leap_years.c
./a.out
```

Result: A list with all the years from 1584 to 2101 that are leap years.

4. Timezone

```
gcc ./calendar/timezone.c
./a.out
```

Result: Correctly formatted time from the epoch depending on the system's timezone.

5. Get current week:

```
gcc ./calendar/week.c
./a.out
```

Result: A nicely formatted current week and day.

6. Print current month:

```
gcc ./calendar/month.c
./a.out
```

Result: A nicely formatted grid of the current date, highlighting current day.