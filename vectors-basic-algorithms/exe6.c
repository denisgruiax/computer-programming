#include <stdio.h>
#include <math.h>

unsigned int n;
float v[5];

void main()
{

    printf("n trebuie sa apartina de [1,5]\nn = ");

    scanf("%u", &n);

    for (size_t i = 0; i < n; i++)
    {
        printf("v[%i] = ", i);
        scanf("%f", &v[i]);
    }
    
    printf("Numere mai mari ca 10:\n\n");

    for (size_t i = 0; i < n; i++)
    {
        if (abs(v[i]) > 10.0)
        {
            printf("%f ", v[i]);
        }
    }
}