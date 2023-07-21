#include <stdio.h>

void main()
{
    unsigned int n, count = 1, i, j, temp;

    printf("n = ");
    scanf("%u", &n);

    int matrix[n][n];

    for (int *i = matrix; i < &matrix[n][0]; i++)
    {
        *i = count;
        count++;
    }

    for (i = 0; i < n; i++)
    {
        for (j = i; j < n; j++)
        {
            temp = *(*(matrix + i) + j);
            *(*(matrix + i) + j) = *(*(matrix + j) + i);
            *(*(matrix + j) + i) = temp;
        }
    }

    printf("\n\n");

    for (i = 0; i < n; i++, putchar('\n'))
        for (j = 0; j < n; j++)
        {
            printf("%i ", matrix[i][j]);
        }
}