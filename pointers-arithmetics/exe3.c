#include <stdio.h>
#include <stdlib.h>

void main()
{
    int *p1, *p2, var1 = 10, var2 = 5;

    p1 = &var1;
    p2 = &var2;
    printf("before: %i %i\n", *p1, *p2);
    *p1 = *p2 + *p1;
    *p2 = *p1 - *p2;
    *p1 = *p1 - *p2;
    printf("after: %i %i", *p1, *p2);
}