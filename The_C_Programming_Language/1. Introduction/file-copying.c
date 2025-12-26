#include <stdio.h>

// copy input to output ver1
int main()
{
  int c;

  c = getchar();
  while (c != EOF) {
    putchar(c);
    c = getchar();
  }

  return 0;
}