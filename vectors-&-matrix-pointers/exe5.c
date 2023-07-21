#include <stdio.h>

void main()
{
    unsigned int n, count = 1;
    printf("n = ");
    scanf("%u", &n);

    int suma_linii[20] = {0}, suma_coloane[20] = {0};
    int matrix[n][n];

    puts("---------------------");
    for (int *p = matrix; p < &matrix[n][0]; p++)
    {
        *p = count;
        count++;
        printf("%i ", *p);
    }
    puts("\n---------------------");
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < n; j++)
        {
            suma_linii[i] += *(*(matrix + i) + j);
            suma_coloane[i] += *(*(matrix + j) + i);
        }

    for (int *p = matrix; p < &matrix[n][0]; p++)
    {
        printf("%i ", *p);
    }

    printf("\n");

    printf("suma_linii\tsuma_coloane\n");

    for (size_t i = 0; i < n; i++)
    {
        printf("%i\t\t%i\n", suma_linii[i], suma_coloane[i]);
    }
}