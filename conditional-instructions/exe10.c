#include <stdio.h>
#include <math.h>

void main()
{
    double u;

    printf("Introduceti masura in radiani: ");
    scanf("%lf", &u);

    if (u < 2 * acos(-1))
    {
        if ((u >= 0) && (u < (acos(-1) / 2)))
        {
            printf("cadranul 1.\n");
        }
        else if ((u >= (acos(-1) / 2)) && (u < (acos(-1))))
        {
            printf("cadranul 2.\n");
        }
        else if ((u >= (acos(-1))) && (u < (2 * acos(-1) / 3)))
        {
            printf("cadranul 3.\n");
        }
        else if ((u >= (2 * acos(-1) / 3)) && (u < (2 * acos(-1))))
        {
            printf("cadranul 4.\n");
        }
    }
    else
    {
        printf("Valoare mult prea mare.\n");
    }
}