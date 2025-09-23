#include <stdio.h>
#include <float.h>

int main()
{
    printf("Float max = %e\n", FLT_MAX);
    printf("Double max = %e\n", DBL_MAX);
    printf("Long double max = %Le\n", LDBL_MAX);

    return 0;
}