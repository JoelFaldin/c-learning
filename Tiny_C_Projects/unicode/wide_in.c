#include <stdio.h>
#include <wchar.h>
#include <locale.h>

wchar_t *trimming(wchar_t *s) {
    int len = wcslen(s);
    int x;

    wchar_t *new_s;

    new_s = s;
    new_s[len - 1] = '\0';

    return new_s;
}

int main() {
    const int size = 32;
    wchar_t input[size], *new_input;

    setlocale(LC_CTYPE, "en_US.UTF-8");

    wprintf(L"Type some fancy text: ");
    fgetws(input, size, stdin);

    new_input = trimming(input);

    wprintf(L"You typed: '%ls'\n", new_input);

    return 0;
}