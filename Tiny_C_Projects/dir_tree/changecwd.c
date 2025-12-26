#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    char cwd[BUFSIZ];
    int r;

    getcwd(cwd, BUFSIZ);
    printf("Current dir: %s\n", cwd);

    r = chdir("..");
    if (r == -1) {
        fprintf(stderr, "Unable to change directories\n");
        exit(1);
    }

    getcwd(cwd, BUFSIZ);
    printf("Current directory (after change): %s\n", cwd);

    return 0;
}