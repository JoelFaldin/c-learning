# Hex dumper

Working with bit and bytes!

1. Print size in bits of different data types:

```
cc hex/byte_sizes.c -lm
./a.out
```

Result:
```
    Byte  8 bits                   256
    Byte 16 bits                 65536
    Byte 32 bits            4294967296
    Byte 64 bits  18446744073709551616
```

2. Details about file (in hex):

```
gcc hex/dumfile.c
./a.out .a.out
```

Result: `A very very long hex output`
You can also just run `./a.out` and it will prompt for a file. Pass `./.a.out` again and you will get the same result!