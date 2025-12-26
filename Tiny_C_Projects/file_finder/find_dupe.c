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
    int repeat;
    char name[BUFSIZ];
    char path[PATH_MAX];
    struct finfo *next;
};

struct finfo *find(char *dirpath, char *parentpath, struct finfo *f) {
    DIR *dp;
    struct dirent *entry;
    struct stat fs;
    char subdirpath[PATH_MAX], fullpath[PATH_MAX];
    int i;

    dp = opendir(dirpath);
    if (dp == NULL) {
        fprintf(stderr, "Unable to read dir '%s'\n", dirpath);
        exit(1);
    }

    while ((entry = readdir(dp)) != NULL) {
        snprintf(fullpath, PATH_MAX, "%s/%s", dirpath, entry -> d_name);
        stat(fullpath, &fs);
        
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

            if (f -> next == NULL) {
                fprintf(stderr, "Unable to allocate new structure\n");
                exit(1);
            }

            i = f -> index;
            f = f -> next;
            f -> index = i + 1;
            f -> repeat = 1;

            strcpy(f -> name, entry -> d_name);
            strcpy(f -> path, dirpath);

            f -> next = NULL;
        }
    }
    
    if (chdir(parentpath) == -1) {
        if (parentpath == NULL) {
            return f;
        }

        fprintf(stderr, "Parent dir lost\n");
        exit(1);
    }

    return f;
}

int main() {
    char startdir[PATH_MAX];
    struct finfo *first, *current, *scan;
    int found = 0;

    first = malloc(sizeof(struct finfo) * 1);

    if (first == NULL) {
        fprintf(stderr, "Unable to alocate memory%n");
        exit(1);
    }

    first -> index = 0;

    strcpy(first -> name, "");
    strcpy(first -> path, "");

    first -> next = NULL;

    getcwd(startdir, PATH_MAX);

    if (chdir(startdir) == -1) {
        fprintf(stderr, "Unable to access dir %s\n", startdir);
        exit(1);
    }

    struct finfo *tail = find(startdir, ".", first);
    
    current = first -> next;
    while (current) {
        if (current -> index > 0) {
            scan = current -> next;
            while (scan) {
                if (strcmp(current -> name, scan -> name) == 0) {
                    current -> repeat++;
                    found = 1;
                }

                scan = scan -> next;
            }

            // printf("%d: %s/%s (%d)\n", current -> index, current -> path, current -> name, current -> repeat);
            current = current -> next;
        }
    }

    current = first -> next;
    while (current) {
        if (current -> index > 0) {
            if (current -> repeat > 1) {
                printf("%d duplicates found of %s:\n", current -> repeat, current -> name);
                printf("%s/%s\n", current -> path, current -> name);
            }

            scan = current -> next;
            while (scan) {
                if (strcmp(scan -> name, current -> name) == 0) {
                    printf(" %s/%s\n", scan -> path, scan -> name);
                }

                scan = scan -> next;
            }
        }

        current = current -> next;
    }

    if (!found) {
        puts("No duplicates found");
        return 1;
    }

    return 0;
}
