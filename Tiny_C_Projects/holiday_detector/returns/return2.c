#include <stdio.h>
#include <stdlib.h>

int main() {
    int r;

    r = system("./return 99");
    printf("The return value is %d\n", r);

    return r;
}
