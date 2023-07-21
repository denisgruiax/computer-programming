#include <stdio.h>

void main()
{
    unsigned int n, n2;

    printf("n = ");
    scanf("%u", &n);

    printf("lunigime sir: ");
    scanf("%u", &n2);

    char a[n][n];
    char sir[n2];

    printf("sir: ");
    scanf("%s", sir);

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            printf("a[%u][%u] = ", i, j);
            scanf(" %c", &a[i][j]);
        }
    }

    int down, up, left, right, count, flag1, flag2, flag3, flag4;

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            flag1 = flag2 = flag3 = flag4 = 1;
            up = down = i, left = right = j;
            count = 0;

            while (count < n2)
            {
                if (sir[count] != a[down][j]) //!Incrementariile nu se vor oprii si daca gasesc valori diferite 
                    flag1 = 0;

                if (sir[count] != a[up][j]) //Todo: implementare de while-uri cu break-uri, se va schimba radical algoritmul.
                    flag2 = 0;

                if (sir[count] != a[i][left]) 
                    flag3 = 0;

                if (sir[count] != a[i][right])
                    flag4 = 0;

                down++, up--, left--, right++, count++;
            }

            if (flag1)
            {
                printf("Linia %u, coloana %i in jos.\n", i, j);
            }

            if (flag2)
            {
                printf("Linia %u, coloana %i in sus.\n", i, j);
            }

            if (flag3)
            {
                printf("Linia %u, coloana %i spre stanga.\n", i, j);
            }

            if (flag4)
            {
                printf("Linia %u, coloana %i spre dreapta.\n", i, j);
            }
        }
    }
}