#include <wchar.h>
#include <locale.h>

int main() {
    wchar_t s[] = L"I 3 to code\n";
    s[2] = 0x2665;

    setlocale(LC_CTYPE, "en_US.UTF-8");

    wprintf(L"%ls", s);

    return 0;
}