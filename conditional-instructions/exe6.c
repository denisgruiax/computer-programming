#include <stdio.h>

void main()
{
    int x, y, z;

    printf("x = ");
    scanf("%i", &x);

    printf("y = ");
    scanf("%i", &y);

    printf("z = ");
    scanf("%i", &z);

    printf("Maxim: %i\n", (x > y) ? ((x > z ? x : z)) : ((y > z) ? y : z));
}