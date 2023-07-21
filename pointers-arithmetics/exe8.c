#include <stdio.h>

void main()
{
    int a[20] = {7, -5, 4, 3, -9, 2, -8}, *p, *q, n = 7;

    for (p = a; p < &a[n]; p++)
    {
        for (q = &a[n]; q > p; q--)
            *q = *(q - 1);
        *q = -(*q);
        n++;
        p++;
    }

    for (p = a; p < &a[n]; p++)
        printf("%i ", *p);
}