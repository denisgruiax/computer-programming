#include <stdio.h>

void sort(int *p, int *q);

void main()
{
    int a, b;

    printf("inserati 2 valori pe aceeasi linie: ");
    scanf("%i %i", &a, &b);

    sort(&a, &b);
    printf("sortate: %i %i", a, b);
}

void sort(int *p, int *q)
{
    if (*p > *q)
    {
        int temp = *q;
        *q = *p;
        *p = temp;
    }
}