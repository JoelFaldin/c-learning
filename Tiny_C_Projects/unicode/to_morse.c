#include <stdio.h>
#include <ctype.h>

void to_morse(char c) {
    const char *morse_alpha[] = {
        ".-", "-...", "-.-.", "-..", ".", "..-.",
        "--.", "....", "..", ".---", "-.-", ".-..",
        "--", "-.", "---", ".--.", "--.-", ".-.", "...",
        "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
    };

    const char *morse_digit[] = {
        ".-----", "..---", "...--", "....-",
        ".....", "-....", "--...", "---..",
        "----.", "-----"
    };

    if (isalpha(c)) {
        c = toupper(c);
        printf("%s ", morse_alpha[c - 'A']);
    } else if (isdigit(c)) {
        printf("%s ", morse_digit[c - '0']);
    } else if (c == ' ' || c == '\n') {
        putchar('\n');
    } else {
        return;
    }
}

int main()  {
    char c = 'a';

    to_morse(c);

    return 0;
}