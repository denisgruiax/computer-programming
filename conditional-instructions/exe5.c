#include <stdio.h>

void main()
{
    int x, y;

    printf("x = ");
    scanf("%i", &x);

    printf("y = ");
    scanf("%i", &y);
    
    int rez =((x >> ((sizeof(x)*8)-1) & 1) ^ (y >> ((sizeof(y)*8)-1) & 1));

    if (rez)
    {
        printf("Numerele x si y nu au acelasi semn.\n");
    }
    else
    {
        printf("Numerele x si y au acelasi semn.\n");
    }
    
}