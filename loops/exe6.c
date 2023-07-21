#include <stdio.h>

void main()
{
    int m, n;

    printf("m = ");
    scanf("%i", &m);

    printf("n = ");
    scanf("%i", &n);

    for (size_t i = 0; i <= n; i++)
    {
        for (size_t j = 0; j <= m; j++)
        {
            printf("%i ", j);
        }
    }
}