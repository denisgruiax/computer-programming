#include <stdio.h>

void main()
{
    int n = 123;
    while (n > 10)
    {
        printf("%i ", n);
        n -= n / 10;
    }
}