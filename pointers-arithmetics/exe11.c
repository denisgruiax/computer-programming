#include <stdio.h>

void main()
{
    int a[100] = {0}, *p, *q, *end = a, temp;

    for (;;)
    {
        printf("v[%i] = ", end - a);
        scanf("%i", end);
        if (!(*end) && ((end - a) < 100))
            break;
        end++;

        for (p = a; p < end; p++)
            for (q = a; q < end; q++)
                if ((*q > *(q + 1)) && (*(q + 1) != 0))
                {
                    temp = *q;
                    *q = *(q + 1);
                    *(q + 1) = temp;
                }

        printf("sortat: ");

        for (p = a; p < end; p++)
            printf("%i ", *p);
        printf("\n");
    }
}