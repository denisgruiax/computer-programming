#include <stdio.h>

int n, vector[10];

void citire();
void mesaj();

void main()
{

    printf("n = ");
    scanf("%i", &n);

    citire();
    mesaj();
}

void citire()
{
    for (size_t i = 0; i < n; i++)
    {
        printf("v[%i] = ", i);
        scanf("%i", &vector[i]);
    }
}

void mesaj()
{
    int store = 1;
    for (size_t i = 0; i < sizeof(vector) / sizeof(int); i++)
    {
        if ((vector[i] >= 0) && (vector[i] % 2 != 0))
        {
            store = 0;
        }
    }

    store?printf("Toate valorile pozitive sunt pare.")\
    :printf("Nu toate valorile pozitive sunt pare.");
}