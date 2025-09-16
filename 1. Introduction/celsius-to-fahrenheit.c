#include <stdio.h>

// print celsius-fahrenheit table
int main()
{
  float celsius, fahr;
  float lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  celsius = lower;

  printf("Celsius to farenheit table");

  while (celsius <= upper) {
    fahr = celsius * (9.0 / 5.0) - 32;
    printf("%3.0f %6.1f\n", celsius, fahr);
    celsius = celsius + 20;
  }

  return 0;
}