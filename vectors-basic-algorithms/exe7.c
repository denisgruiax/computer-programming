#include <stdio.h>

void main()
{
    unsigned int n;
    int vector[10];

    printf("n (0,11) = ");
    scanf("%u", &n);

    for (size_t i = 0; i < n; i++)
    {
        printf("v[%i] = ", i);
        scanf("%i", &vector[i]);
    }

    int temp;

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            if ((vector[j] % 2 == 0) && (vector[j + 1] % 2 == 1))
            {
                temp = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = temp;
            }
        }
    }

    for (size_t i = 0; i < n; i++)
    {
        printf("%i ", vector[i]);
    }
}