#include <stdio.h>

int x[100];

int main()
{
    
    int i, j, n;

    printf("Dati valoarea lui n = ");
    scanf("%i", &n);
    for (i = 0; i < n; i++)
    {
        printf("x[i] = ");
        scanf("%i", &x[i]);
    }

    for (i = 0; i < n; i++)
        if (x[i] % 2 == 1)
        {
            for (j = n; j > i; j--)
            {
                x[j] = x[j-1];
            }
            x[i] = 0;
            i++;
            n++;
        }

    for (i = 0; i < n; i++)
        printf("%i ", x[i]);

    return 0;
}