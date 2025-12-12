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