#include <stdio.h>

int bin_search(int x, int v[], int n);

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    int target = 7;
    int index = bin_search(target, arr, n);

    printf("Location: %d\n", index);

    return 0;
}

// bin search: finx x in v[0] <= v[1] <= ... <= v[n - 1]
int bin_search(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;

    while (low <= high) {
        mid = (low + high) / 2;

        if (x < v[mid]) {
            high = mid - 1;
        } else if (x > v[mid]) {
            low = mid + 1;
        } else {
            return mid;
        }
    }

    return -1;
}