#include <wchar.h>
#include <locale.h>

int main() {
    // 0xa5: yen sign:
    wchar_t yen = 0xa5;    

    setlocale(LC_CTYPE, "en_US.UTF-8");

    wprintf(L"That will be %lc500\n", yen);

    wchar_t s[] = L"That will be $500\n";
    s[13] = 0xa5;

    wprintf(L"%ls", s);

    return 0;
}