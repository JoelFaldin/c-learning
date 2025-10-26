# I/O Filters

Redirection characters and their functions:

| Character | Name          | What it does     |
| --------- | ------------- | ---------------- |
| >         | Greater than  | Redirects output |
| <         | Less than     | Redirects input  |
| \|        | Pipe          | Sends output through another program|

Examples:

```
cc io_filters/random.c
echo "Markdown is great" | ./a.out
```

Result: "mArkdowN iS GreAT"

```
cc io_filters/random.c
./a.out < io_filters/text.txt
```

Result: "c is pREttY NeaT"

```
cc io_filters/random.c
echo "C is fast" | ./a.out > io_filters/random_note.txt
```

Result: file "random_note.txt" created with text "c is fASt"

---

Contents of file `text.txt`:

`C is pretty neat`