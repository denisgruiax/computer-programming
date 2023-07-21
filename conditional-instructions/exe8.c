#include <stdio.h>

void main()
{
    unsigned int n;
    printf("n (n >= 5): ");
    scanf("%u", &n);

    printf("Cele mai mari numere impare conscutive mai mici de cat %u:\n", n);
    if (n % 2 == 0)
    {
        printf("%u si %u\n", n - 1, n - 3);
    }
    else
    {
        printf("%u si %u\n", n - 2, n - 4);
    }
}