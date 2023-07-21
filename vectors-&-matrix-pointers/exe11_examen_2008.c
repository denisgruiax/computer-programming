#include <stdio.h>

void print_s(int **p, unsigned int m)
{
    for (size_t i = 0; i < m; i++, printf("\n"))
    {
        for (size_t j = 0; j < m; j++)
        {
            printf(" %i ", *(*(p + i) + j));
        }
    }
}
void main()
{
    unsigned int m, n;

    printf("m = ");
    scanf("%u", &m);

    printf("n = ");
    scanf("%u", &n);

    int a[m][m], b[n][n];

    printf("Matricea 1:\n");

    for (size_t i = 0; i < m; i++)
        for (size_t j = 0; j < m; j++)
        {
            printf("(%u, %u) = ", i, j);
            scanf("%i", &a[i][j]);
        }

    printf("Matricea 2:\n");

    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < n; j++)
        {
            printf("(%u, %u) = ", i, j);
            scanf("%i", &b[i][j]);
        }
    int c1 = 0, c2 = 0, c3 = 0, c4 = 0, flag = 1, count = 0;
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            flag = 1;
            for (c1 = i, c3 = 0; c1 < (i + n); c1++, c3++)
                for (c2 = j, c4 = 0; c2 < (j + n); c2++, c4++)
                {
                    if (a[c1][c2] != b[c3][c4])
                    {
                        flag = 0;
                        break;
                    }
                }
            if (flag)
            {
                printf("(%i, %i) & (%i, %i)\n", i, j, i + (n - 1), j + (n - 1));
            }
        }
    }
}