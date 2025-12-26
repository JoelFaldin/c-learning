#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

char *commify(float v) {
    char buff[MAX];
    char *value = malloc(MAX);
    int len, j, k;

    snprintf(buff, MAX, "%.0f", v);
    len = strlen(buff);
    int i = len - 1;

    k = 0;
    j = 0;
    while (i >= 0) {
        value[k++] = buff[i--];
        j++;

        if (j % 3 == 0 && i >= 0) {
            value[k++] = ',';
        }
    }

    value[k] = '\0';

    for (int a = 0, b = k - 1; a < b; a++, b--) {
        char tmp = value[a];
        value[a] = value[b];
        value[b] = tmp;
    }

    return value;
}

int main() {
    int items, draw, x;
    unsigned long long i, d;

    printf("Number of items: ");
    scanf("%d", &items);
    if (items == 0) {
        fprintf(stderr, "You should input a value larger than 0");
        return 1;
    }

    printf("Items to draw: ");
    scanf("%d", &draw);
    if (draw == 0) {
        return 1;
    }

    if (items < draw) {
        fprintf(stderr, "The number of items drawn should not exceed the number of items available.");
        return 1;
    }
    
    i = items;
    d = draw;

    for (x = 1; x < draw; x++) {
        i *= items - x;
        d *= draw - x;
    }

    printf("Your odds of drawing %d ", draw);
    printf("items from %d are:\n", items);
    
    char *result = commify((float)i / (float)d);
    printf("\t1:%s\n", result);

    free(result);

    return 0;
}