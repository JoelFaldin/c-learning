# Unicode

Handling different characters usning UNICODE

1. Write Greek alphabet into a file (make sure to create `unicode/text.txt` before):

```
cc unicode/uppercase_greek.c
./a.out
```

Result: `ΑΒΓΔΕΖΗΘΙΚΛΜΝΞΟΠΡΣΤΥΦΧΨΩ`
And also, the alphabet will be written to `unicode/text.txt` file

2. Read content from `unicode/text.txt` and print to console (make sure to have `unicode/text.txt` created and with content inside):

```
cc unicode/greek_read.c
./a.out
```

Result:
```
Reading from unicode/text.txt:
ΑΒΓΔΕΖΗΘΙΚΛΜΝΞΟΠΡΣΤΥΦΧΨΩ
```