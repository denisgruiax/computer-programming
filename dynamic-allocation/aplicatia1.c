#include <stdio.h>
#include <stdlib.h>

unsigned int m, n;

int *read(unsigned int size);
void foo(int *p, int *q);

int main()
{
    int *v, *v1;

    printf(" m si n:");
    scanf("%u %u", &m, &n);

    v = read(m);
    v1 = read(n);

    foo(v, v1);

    free(v);
    free(v1);

    return 0;
}

int *read(unsigned int size)
{
    int *p;

    p = (int *)malloc(sizeof(int) * size);

    if (!p)
    {
        puts("Eroare...");
        exit(EXIT_FAILURE);
    }

    for (unsigned int i = 0; i < size; i++)
    {
        printf("v[%i] = ", i);
        scanf("%i", &p[i]);
    }

    printf("\n");
    
    return p;
}

void foo(int *p, int *q)
{
    unsigned int i, j;

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
            if (*(p + i) == *(q + j))
                printf("%i ", *(p + i));

        if (j == (n - 1))
            break;
    }
    printf("\n");
}