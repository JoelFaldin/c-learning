#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BSIZE 256

int main()
{
    const char filename[] = "daily_greetings/pithy.txt";
    FILE *fp;
    char buffer[BSIZE];
    char *r, *entry;
    int items, saying;
    char **list_base;

    fp = fopen(filename, "r");

    if (fp == NULL) {
        fprintf(stderr, "Unable to open file %s\n", filename);
        exit(1);
    }

    list_base = (char **)malloc(sizeof(char *) * 100);
    if (list_base == NULL) {
        fprintf(stderr, "Unable to allocate memory\n");
        exit(1);
    }

    items = 0;
    while (fgets(buffer, BSIZE, fp) != NULL) {
        entry = (char *)malloc(sizeof(char) * strlen(buffer) + 1);

        if (entry == NULL) {
            fprintf(stderr, "Unable to allocate memory\n");
            exit(1);
        }
        
        strcpy(entry, buffer);
        *(list_base + items) = entry;
        items++;

        if (items % 100 == 0) {
            char **tmp = realloc(list_base, sizeof(char *) * (items + 100));

            if (tmp == NULL) {
                fprintf(stderr, "Unable to reallocate memory\n");
                exit(1);
            }

            list_base = tmp;
        }
    }

    fclose(fp);

    srand((unsigned int) time(NULL));
    saying = rand() % items;

    printf("%s", *(list_base + saying));

    int x;
    for (x = 0; x < items; x++) {
        free(list_base[x]);
    }

    free(list_base);

    return 0;
}