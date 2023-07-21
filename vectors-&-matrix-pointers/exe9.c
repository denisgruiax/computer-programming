#include <stdio.h>

void main()
{
    unsigned int n;

    printf("n = ");
    scanf("%u", &n);

    unsigned int a[n][n];

    for (size_t i = 0; i < n; i++, printf("\n"))
        for (size_t j = 0; j < n; j++)
        {
            a[i][j] = 0;
        }

    for (int i = 0, j = (n - 1); i < n; i++, j--)
    {
        a[i][i] = 1;
        a[i][j] = 1;
    }

    for (size_t i = 0; i < n; i++, printf("\n"))
        for (size_t j = 0; j < n; j++)
        {
            printf(" %u ", a[i][j]);
        }
}