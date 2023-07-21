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

    if ((x <= z) && (z < y))
    {
        printf("Z se afla in intervalul [x, y)");
    }
    else
    {
        printf("Z nu se afla in intervalul [x, y)");
    }
    
}