# File finder

Utilities to search for a file in a directory/group of directories.

1. Find a file in a dir:

```
gcc file_finder/find.c
./a.out
*.c
```

Result: `Searching for '*.c'`, then it prints all files matching the wildcard (or name) with its location (or 0 matches if no files are found). It also searches through multiple directories!

2. Find one or more files:

```
gcc file_finder/glob.c
./a.out
*.c
```

Result: `Filename or wildcard: '*.c'`, and then a list of files that matches the string. It also prints `No matches for '*.c'` if no files are found.
