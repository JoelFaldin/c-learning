# Encoding and decoding

Encoding and decoding hex values to char/int

Usage of files:

1. ASCII table
```
cc encoding_decoding/ascii.c
./a.out
```

Result: A formatted table of different values in decimal, hexadecimal and the character they represent

2. bin_string
```
cc encoding/decoding/bin_string
./a.out
```

Result: A character/binary representation of the same values
Character: A    Binary: 01000001

3. Case tricks

Tricks to manipulate binary values. It uses **bitmasks**.

| Character | ASCII Decimal | Binary    |
| --------- | ------------- | --------- |
| 'A'       | 65            | 0100 0001 |
| 'a'       | 97            | 0110 0001 |

Converting to lowercase: `char lower = c | 0x20;`
Converting to uppercase: `char upper = c & ~0x20;`

**Bitmasks** are hexadecimal literals written in base 16.
`0x` = This number is in hexadecimal.

| Hex  | Decimal | Binary |
| ---- | ------- | ------ |
| 0x20 | 32      | 0010 0000 |
| 0xDF | 223     | 1101 1111 |
| 0x5F | 95      | 0101 1111 |

4. Encoding and decoding to hex

```
cc encoding_decoding/hexenfilter.c
./a.out
test
```

Result: `746573740a`

```
cc encoding_decoding/tohex.c
./a.out
746573740a
```

Result: `test`