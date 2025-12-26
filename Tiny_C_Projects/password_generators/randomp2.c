#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define UPPER 1
#define LOWER 6
#define NUM 1
#define SYM 2

char uppercase();
char lowercase();
char number();
char symbol();
void scramble(char p[]);

int main() {
    srand((unsigned)time(NULL));

    char password[UPPER + LOWER + NUM + SYM + 1];
    int x;

    password[0] = uppercase();

    while(x < UPPER) {
        password[x] = uppercase();
        x++;
    }
    while(x < UPPER + LOWER) {
        password[x] = lowercase();
        x++;
    }
    while(x < UPPER + LOWER + NUM) {
        password[x] = number();
        x++;
    }
    while(x < UPPER + LOWER + NUM + SYM) {
        password[x] = symbol();
        x++;
    }

    password[x] = '\0';

    scramble(password);

    printf("Final password: %s\n", password);

    return 0;
}

char uppercase() {
    char ch;

    // Range: 65 to 90 (A to Z):
    ch = rand() % ('Z' - 'A' + 1) + 'A';
    return ch;
}

char lowercase() {
    char ch;

    // Range: 97 to 122 (a to z):
    ch = rand() % ('z' - 'a' + 1) + 'a';
    return ch;
}

char number() {
    char ch;

    // Range: 0 to 9:
    ch = rand() % (9 - 0 + 1) + 0;

    char n;
    sprintf(&n, "%d", ch); 
    return n;
}

char symbol() {
    char symbols[] = {'!', '@', '#', '$', '%', '*', '_', '-'};
    int num;
    char ch;

    // Range: 0 to 7:
    num = rand() % (7 - 0 + 1) + 0;
    ch = symbols[num];
    return ch;
}

void scramble(char p[]) {
    const int size = UPPER + LOWER + NUM + SYM + 1;
    char key[size];
    int x, r;

    for (x = 0; x < size; x++) {
        key[x] = '\0';
    }

    x = 0;
    while (x < size - 1) {
        r = rand() % (size - 1);
        if (!key[r]) {
            key[r] = p[x];
            x++;
        }
    }

    for (x = 0; x < size; x++) {
        p[x] = key[x];
    }
}