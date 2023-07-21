#include <stdio.h>

void main()
{
    int a[] = {5, 8, 1, 4, 2, 6, 9, 8, 4, 3, 5, 8, 9, 0, 4, 2, 1, 4, 8,7}, *p, *q, n = (sizeof(a) / sizeof(int)) - 1;

    for (p = a; p <= &a[n]; p++)
        if (*p % 2 == 0)
        {
            for (q = p; q <= &a[n]; q++)
            {
                *(q) = *(q+1);
            }
            n--;
            p--;
        }

    for (p = a; p <= &a[n]; p++)
        printf("%i ", *p);
}