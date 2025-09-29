#include <stdio.h>
#include "converter.h"

int main()
{
    double c = 25;

    printf("%.2f °C = %.2f °F\n", c, celsius_to_fahrenheit(c));
    return 0;
}