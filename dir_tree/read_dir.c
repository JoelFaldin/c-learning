#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main() {
    DIR *dp;
    struct dirent *entry;

    dp = opendir("./dir_tree");
    if (dp == NULL) {
        puts("Unable to read directory");
        exit(1);
    }

    while ((entry = readdir(dp)) != NULL) {
        printf("File %s\n", entry -> d_name);
    }

    // puts("Directory is open!");

    closedir(dp);
    // puts("Directory closed!");

    return 0;
}