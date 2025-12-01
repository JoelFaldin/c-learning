#include <wchar.h>
#include <locale.h>

int main() {
    wchar_t suits[4] = {
        0x2660, 0x2665, 0x2663, 0x2666
    };

    int x;

    setlocale(LC_CTYPE, "en_US.UTF-8");

    for (x = 0; x < 4; x++) {
        putwchar(suits[x]);
    }

    putwchar('\n');

    return 0;
}