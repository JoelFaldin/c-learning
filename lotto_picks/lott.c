#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *bubble_sort(int arr[]) {
    int len = 5;
    int i, j, temp;
    int *result = malloc(len * sizeof(int));

    for (i = 0; i < len - 1; i++) {
        for(j = 0; j < len - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    for (i = 0; i < len; i++) {
        result[i] = arr[i];
    }

    return result;
}

int main() {
    const int balls = 69, draw = 5;
    int x, y, r;
    int winners[draw];
    int *sorted_numbers;

    srand((unsigned)time(NULL));

    printf("Drawing %d numbers from %d balls:\n", draw, balls);

    for (x = 0; x < draw; x++) {
        winners[x] = rand() % balls + 1;
    }

    for (x = 0; x < draw - 1; x++) {
        for (y = x + 1; y < draw; y++) {
            if (winners[x] == winners[y]) {
                winners[y] = rand() % balls + 1;
                y = draw;
                x = -1;
            }
        }
    }

    sorted_numbers = bubble_sort(winners);

    for (r = 0; r < draw; r++) {
        if (r != 0) {
            printf(" - ");
        }

        printf("%d", sorted_numbers[r]);
    }

    free(sorted_numbers);

    return 0;
}