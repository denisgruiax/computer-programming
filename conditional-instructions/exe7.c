#include <stdio.h>

unsigned int function2(int numar)
{
    if (numar < 10)
    {
        return ((numar % 2 == 1) ? 1 : 0);
    }
    else
    {
        return (((numar % 10) % 2 == 1) ? 1 : 0) + (function2(numar / 10));
    }
}

void main()
{
    int numar_3Cifre;

    printf("Numar = ");
    scanf("%i", &numar_3Cifre);

    printf("Numar de cifre impare: %u\n", function2(numar_3Cifre));
}