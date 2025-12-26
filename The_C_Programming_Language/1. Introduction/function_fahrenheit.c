#include <stdio.h>

int fahr_to_cels(int m);

int main()
{
    int fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    
    while (fahr <= upper)
    {
        celsius = fahr_to_cels(fahr);
        printf("%d \t %d\n", fahr, celsius);
        fahr = fahr + step;
    }
}

// fahr_to_cels: convert fahrenheit to celsius
int fahr_to_cels(int fahr)
{
    int celsius;

    celsius = 5 * (fahr - 32) / 9;

    return celsius;
}