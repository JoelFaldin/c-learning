#include <stdio.h>
#include <string.h>

char is_term(char *term);

int main() {
    char text[64];
    char *match;
    char ch;

    printf("Enter NATO text: ");
    fgets(text, 64, stdin);

    match = strtok(text, " ");
    while (match) {
        if ((ch = is_term(match)) != '\0') {
            putchar(ch);
        }
        match = strtok(NULL, " ");
    }
    putchar('\n');

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