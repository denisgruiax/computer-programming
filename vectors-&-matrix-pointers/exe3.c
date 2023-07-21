#include <stdio.h>

void main()
{
    unsigned int m, n;

    printf("m = ");
    scanf("%u", &m);

    printf("n = ");
    scanf("%u", &n);

    int v[m][n], count = 1, *i, *j;

    for (i = &v; i < &v[m][0]; i++)
    {
        *i = count;
        count++;
    }

    for (i = &v; i < &v[m][0]; i++)
            printf("%i ", *i);

    printf("\n\n");

    for (size_t i = 0; i < m; i++, printf("\n"))
        for (size_t j = 0; j < n; j++)
        {
            printf("%i ", v[i][j]);
        }
        
    
}