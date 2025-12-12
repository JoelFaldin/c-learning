# Holiday detector

A series of functions/exercises regarding holiday detection from the USA.

1. Get current date:

```
gcc ./holiday_detector/get_date.c
./a.out
```

Result: `Today is [weekday] [day number], [month], year`

2. Get details about an specific date

```
gcc ./holidays_detector/get_date2.c
./a.out
```

Result: `11/04/2022 is on a Monday`
Format: DD/MM/YY

3. Get easter dates from the past and future:

```
gcc ./holiday_detector/easter.c -lm
./a.out
```

Result: Multiple messages with easter day for each year, starting in 2018 until 2035.

4. is_holiday functions

The `is_holiday.c` file contains functions and a `main` with useful logic.
The file uses `math.h` library, and to run its `main` add `-DTEST_MAIN`.
To compile the file and run its `main`:

```
gcc -DTEST_MAIN ./holiday_detector/is_holiday.c -lm
./a.out
```

Result: `Today is [DAY]/[MONTH]/[YEAR], [message depending if its holiday]`

5. Running the gauntlet

The `gauntlet.c` file includes a `for` loop to run the `is_holiday` function against every day in a year. It uses the `functions.h` file (which 'imports' functions and struct from the `is_holiday.c` file).

```
gcc ./holiday_detector/gauntlet.c ./holday_detector/is_holiday.c -lm
./a.out
```

Result: Multiple messages with each day from 2022, starting from january 01 to december 31. It also displays a message depending on if its a holiday.