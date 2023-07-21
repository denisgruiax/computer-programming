#include <stdio.h>

void main()
{
    unsigned int n;

    printf("numar persoane = ");
    scanf("%u", &n);

    int v[n][n], j = 0, nr_prieteni[n];

    for (int i = 0; i < n; i++)
    {
        j = 0;
        printf("prietenii lui %i:\n", i);
        while (j < n)
        {
            scanf("%i", &v[i][j]);

            if (v[i][j] == -1)
                break;

            j++;

            if (j == (n - 1))
            {
                v[i][j] = -1;
                break;
            }
        }
    }

    for (size_t i = 0; i < n; i++)
    {
        j = 0;
        nr_prieteni[i] = 0;

        while (v[i][j] != -1)
        {
            nr_prieteni[i]++;
            j++;
        }
    }

    for (size_t i = 0; i < n; i++)
    {
        printf(" %i -> numar prieteni -> %i\n", i, nr_prieteni[i]);
    }
}

/*In program trebuie avut grija sa nu punem ca prieten acelasi numar.*/
/*Afisarea se face de 0, daca introducem n = 5, vor fi 5 persoane -> 0, 1, 2, 3, 4.*/
/*In matricea 'v' sunt stocati si feicare prieten, cu usurinte se poate afisa prietenii lui numarul 3 de exemplu.*/