#include <stdio.h>
#include <unistd.h>

int main() {
    char cwd[BUFSIZ];
    getcwd(cwd, BUFSIZ);

    printf("Current directory: %s", cwd);

    return 0;
}