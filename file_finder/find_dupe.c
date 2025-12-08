#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

#ifndef PATH_MAX
#define PATH_MAX 256
#endif

struct finfo {
    int index;
    char name[BUFSIZ];
    char path[PATH_MAX];
    struct finfo *next;
};

void print_struct(struct finfo *f) {
    printf("%d: %s/%s\n", f -> index, f -> path, f -> name);
}

struct finfo *find(char *dirpath, char *parentpath, struct finfo *f) {
    DIR *dp;
    struct dirent *entry;
    struct stat fs;
    char subdirpath[PATH_MAX];
    int i;

    dp = opendir(dirpath);
    if (dp == NULL) {
        fprintf(stderr, "Unable to read dir '%s'\n", dirpath);
        exit(1);
    }

    while ((entry = readdir(dp)) != NULL) {
        stat(entry -> d_name, &fs);

        if (S_ISDIR(fs.st_mode)) {
            if (strncmp(entry -> d_name, ".", 1) == 0) {
                continue;
            }

            if (chdir(entry -> d_name) == -1) {
                fprintf(stderr, "Unable to change to %s\n", entry -> d_name);
                return f;
            }

            getcwd(subdirpath, BUFSIZ);
            f = find(subdirpath, dirpath, f);
        } else {
            f -> next = malloc(sizeof(struct finfo) * 1);
            print_struct(f);

            if (f -> next == NULL) {
                fprintf(stderr, "Unable to allocate new structure\n");
                exit(1);
            }

            i = f -> index;
            f = f -> next;
            f -> index = i + 1;

            strcpy(f -> name, entry -> d_name);
            strcpy(f -> path, dirpath);

            f -> next = NULL;
        }
    }

    
    if (chdir(parentpath) == -1) {
        if (parentpath == NULL) {
            exit(1);
        }

        fprintf(stderr, "Parent dir lost\n");
        exit(1);
    }

    return f;
}

int main() {
    char startdir[PATH_MAX];
    struct finfo *first, *current;

    first = malloc(sizeof(struct finfo) * 1);

    if (first == NULL) {
        fprintf(stderr, "Unable to alocate memory%n");
        exit(1);
    }

    first -> index = 0;
    // printf("%d\n", first -> index);

    strcpy(first -> name, "");
    strcpy(first -> path, "");

    first -> next = NULL;

    getcwd(startdir, PATH_MAX);

    if (chdir(startdir) == -1) {
        fprintf(stderr, "Unable to access dir %s\n", startdir);
        exit(1);
    }

    find(startdir, NULL, first);

    current = first;
    while (current) {
        if (current -> index > 0) {
            printf("%d: %s/%s\n", current -> index, current -> path, current -> name);
            current = current -> next;
        }
    }

    return 0;
}
