# Caesar cipher

Cipher text with Caesar cipher.

| | | | | | |
| - | - | - | - | - | - |
| A | B | C | ... | Y | Z |
| D | E | F | ... | B | C |

Examples:

1. Cipher normal text:

```
cc caesar/caesar.c
echo "Hello, Caesar!" | ./a.out
```

Result: `Uryyb, Pnrfne!`

2. Double cipher:

```
cc caesar/caesar.c
echo "Hello, Caesar!" | ./a.out | ./a.out
```

Result: `Hello, Caesar!`

3. More complex cipher:

```
cc caesar/caesar02.c -o ./caesar02
cc caesar/caesar03.c -o ./caesar03
echo "Hello, Caesar!" | ./caesar02 | ./caesar03
```

Result: `Hello, Caesar!`