#include <stdio.h>

void main()
{
    unsigned int m, n, p;

    printf("m = ");
    scanf("%u", &m);

    printf("n = ");
    scanf("%u", &n);

    printf("p = ");
    scanf("%u", &p);

    int a[m][n], b[n][p], c[m][p];

    for (size_t i = 0; i < m; i++)
        for (size_t j = 0; j < n; j++)
        {
            printf("a[%i][%i] = ", i, j);
            scanf("%i", &a[i][j]);
        }

    printf("\n");

    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < p; j++)
        {
            printf("b[%i][%i] = ", i, j);
            scanf("%i", &b[i][j]);
        }

    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < p; j++)
        {
            c[i][j] = 0;
            for (size_t k = 0; k < n; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    for (size_t i = 0; i < m; i++, printf("\n"))
    {
        putchar('(');
        for (size_t j = 0; j < p; j++)
        {
            printf(" %i ", c[i][j]);
        }
        putchar(')');
    }
}