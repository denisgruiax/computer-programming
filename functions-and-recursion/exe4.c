#include <stdio.h>

void citire(int v[], unsigned int n);
int egal(int v[], int v2[], unsigned int n);

void main()
{
    unsigned int n;

    printf("n (n < 10) = ");
    scanf("%u", &n);

    int a[n], b[n];

    citire(a, n);
    citire(b, n);

    (egal(a, b, n))?(printf("Egale.\n")):(printf("Nu sunt egale.\n"));
}

void citire(int v[], unsigned int n)
{
    for (unsigned int i = 0; i < n; i++)
    {
        printf("v[%i] = ", i);
        scanf("%i", &v[i]);
    }
    printf("\n");
}

int egal(int v[], int v2[], unsigned int n)
{
    for (unsigned int i = 0; i < n; i++)
    {
        if (v[i] != v2[i])
            return 0;
    }
    return 1;
}