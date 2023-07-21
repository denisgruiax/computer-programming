#include <stdio.h>

#define max(a, b) (a > b ? a : b)
void main()
{
    unsigned int m, n;

    printf("m = ");
    scanf("%u", &m);

    printf("n = ");
    scanf("%u", &n);

    int v[m][n];

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            v[i][j] = max(i, j);
        }
    
    putchar('\n');

    for (int i = 0; i < m; i++, printf("\n"))
        for (int j = 0; j < n; j++)
        {
            printf("%i ", v[i][j]);
        }
}