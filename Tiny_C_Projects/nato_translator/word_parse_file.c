#include <stdio.h>
#include <string.h>

char is_term(char *term);

int main(int argv, char *argc[]) {
    char phrase[64];
    FILE *f;
    char ch;
    char *match;

    if (argv < 2) {
        fprintf(stderr, "You should add a file as argument\n");
        return 1;
    }

    f = fopen(argc[1], "r");

    if (f == NULL) {
        fprintf(stderr, "Error opening file\n");
        return 1;
    }

    while (!feof(f)) {
        fgets(phrase, 64, f);
        match = strtok(phrase, " ,.!?=()[]{}'\"");

        while (match) {
            if ((ch = is_term(match)) != '\0') {
                putchar(ch);
            }

            match = strtok(NULL, " ,.!?=()[]{}'\"");
        }
    }

    putchar('\n');

    fclose(f);

    return 0;
}

char is_term(char *term) {
    const char *nato[] = {
        "Alfa", "Bravo", "Charlie", "Delta", "Echo", "Foxtrot",
        "Golf", "Hotel", "India", "Juliett", "Kilo", "Lima",
        "Mike", "November", "Oscar", "Papa", "Quebec", "Romeo",
        "Sierra", "Tango", "Uniform", "Victor", "Whiskey",
        "Xray", "Yankee", "Zulu"
    };

    int x;
    char *n, *t;

    for (x = 0; x < 26; x++) {
        n = nato[x];
        t = term;

        while (*n != '\0') {
            if ((*n | 0x20) != (*t | 0x20)) {
                break;
            }

            n++;
            t++;
        }

        if (*n == '\0') {
            return (*nato[x]);
        }
    }

    return 0;
}