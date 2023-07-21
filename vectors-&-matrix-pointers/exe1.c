#include <stdio.h>

void main()
{
    unsigned int n, verificare = 1;

    printf("n = ");
    scanf("%u", &n);

    int v[n][n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            printf("v[%i][%i] = ", i, j);
            scanf("%i", &v[i][j]);
        }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if ((v[i][j] != 0) && (i != j))
                verificare = 0;
            if ((v[i][j] != 1) && (i == j))
                verificare = 0;
        }

    if (verificare)
        printf("Este matrice unitate.\n");
    else
        printf("Nu este matrice unitate.\n");
}