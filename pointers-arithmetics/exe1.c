#include <stdio.h>
#include <math.h>

void main()
{
    double *p, *q, a, b;
    p = &a, q = &b;
    scanf("%lf", &a);
    scanf("%lf", &b);

    if (p < q)
    {
        printf("a");
    }
    else
    {
        printf("b");
    }
    
    
}