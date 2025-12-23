# Lotto picks

1. Odds of picking items from a list:

```
gcc ./lotto_picks/odds.c
./a.out
69
5
```

Result: `Your odds of drawing 5 items from 69 are: 1:11,238,513`

2. Output random numbers between 1 and 100:

```
gcc ./lotto_picks/random.c
./a.out
```

Result: A 5x5 grid of random values in range.

3. Pick and compare random values between 1 and 69:

```
gcc ./lotto_picks/lott.c
./a.out
```

Result: 5 values to match, 5 values guessed, and the number of matches between the two.