#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int main() {
    setlocale(LC_CTYPE, "en_US.UTF-8");

    const wchar_t alpha = 0x391;
    const int alpha_dec = 913;

    const wchar_t omega = 0x3a9;
    const int omega_dec = 937;

    const wchar_t no_sigma = 0x3a2;

    int a;

    FILE *f;

    f = fopen("unicode/text.txt", "w");
    if (f == NULL) {
        fprintf(stderr, "Error opening file.");
        return 1;
    }

    wprintf(L"Writting the Greek alphabet...\n");

    for (a = alpha_dec; a <= omega_dec; a++) {
        // wprintf(L"%d\t %lc \n", a, a);
        wprintf(L"%lc", a);

        if (a == no_sigma) {
            continue;
        }

        fputwc(a, f);
    }

    wprintf(L"\nDone");

    fputwc('\0', f);
    fclose(f);


    return 0;
}