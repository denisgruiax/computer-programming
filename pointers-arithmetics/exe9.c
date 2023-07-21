#include <stdio.h>

unsigned int fcn(int p, int *q)
{
    int *end = &q[sizeof(q) / sizeof(int)], *i, result = 1;
    for (i = q; i < end; i++)
    {
        if (*i == p)
        {
            result = 0;
            break;
        }
    }
    return (result);
}
void main()
{
    int a[100] = {0}, b[100] = {0}, *p, *q, *end = a, count = 0;

    for (;;)
    {
        printf("v[%u] = ", (end - a));
        scanf("%i", end);
        if (*end == 0)
            break;
        end++;
    }

    for (p = a; p < end; p++)
        for (q = (p + 1); q < end; q++)
            if ((*p == *q) && (fcn(*p, b)))
            {
                b[count] = *p;
                count++;
                printf("%i ", *p);
            }
}