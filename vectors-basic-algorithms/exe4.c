#include <stdio.h>

int v[] = {7, -5, 4, 3, -9, 2, -8};

void fcn();

void main()
{
    int k;

    printf("k = ");
    scanf("%i", &k);

    fcn(k);
}

void fcn(int k)
{
    int store = 0;

    for (size_t i = 0; i < sizeof(v) / sizeof(int); i++)
    {
        if (v[i] > k)
        {
            store = v[i];
            break;
        }
    }

    store ? printf("%i primul numar gasit mai mare decat %i.\n", store, k) :\
 printf("Nu exista numar mai mare decat k.\n");
}