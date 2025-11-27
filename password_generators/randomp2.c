#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define UPPER 1
#define LOWER 6
#define NUM 1
#define SYM 2

char uppercase();
char lowercase();
int number();
char symbol();

int main() {
    srand((unsigned)time(NULL));

    char password[10];

    password[0] = uppercase();

    for (int i = 1; i <= LOWER; i++) {
        password[i] = lowercase();
    }

    char ch;
    sprintf(&ch, "%d", number());    
    
    password[7] = ch;
    
    for (int j = 8; j < SYM + 8; j++) {
        password[j] = symbol();
    }

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

int number() {
    int num;

    // Range: 0 to 9:
    num = rand() % (9 - 0 + 1) + 0;
    return num;
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
