#include <stdio.h>
unsigned int n;
int v[10];

void citire()
{
    printf("n = ");
    scanf("%u", &n);
    for (size_t i = 0; i < n; i++)
    {
        printf("v[%u] = ", i);
        scanf("%i", &v[i]);
    }
}

void fcn()
{
    unsigned int count;
    for (int i = 0; i < n; i++)
    {
        if (v[i] < v[i + 1])
        {
            for (int j = i; j < n; j++)
            {
                v[j] = v[j + 1];
            }
            n--;
        }
    }
}

void afisare()
{
    printf("Elemente ramase: ");
    for (size_t i = 0; i < n; i++)
    {
        printf("%i ", v[i]);
    }
}
void main()
{
    citire();
    fcn();
    afisare();
}