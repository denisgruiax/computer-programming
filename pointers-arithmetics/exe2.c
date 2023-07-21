#include <stdio.h>

void main()
{
    int a, b, *p;

    scanf("%i %i", &a, &b);
    (a > b) ? (p = &a) : (p = &b);
    printf("%i", *p);
}