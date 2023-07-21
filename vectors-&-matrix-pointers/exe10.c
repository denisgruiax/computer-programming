#include <stdio.h>

void main()
{
    unsigned int n;

    printf("Numar produse: ");
    scanf("%u", &n);

    int a[n][5];

    for (size_t i = 0; i < n; i++)
    {
        printf("Produsl %i:\n", i);
        for (size_t j = 0; j < 4; j++)
        {
            printf("Trimestrul %u: ", j);
            scanf("%i", &a[i][j]);
        }

        if ((a[i][0] < a[i][1]) && (a[i][1] < a[i][2]) && (a[i][2] < a[i][3]))
        {
            a[i][4] = 1;
        }
        else
        {
            a[i][4] = 0;
        }
    }
    
    printf("Produse cu crestere continua: ");

    for (size_t i = 0; i < n; i++)
    {
        if (a[i][4])
        {
            printf("%i ", i);
        }
        
    }
    
}