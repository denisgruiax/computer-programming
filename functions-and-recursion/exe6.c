#include <stdio.h>

int solver(int a, int b);

void main()
{
    printf("%i ", solver(4, 2));
    printf("%i ", solver(7, 3));
    printf("%i ", solver(3, 9));
    printf("%i ", solver(16, 32));
    printf("%i ", solver(25, 125));
}

int solver(int a, int b)
{
    if (a == b)
        return (a);
    if (a > b)
        return (solver(a - b, b));
    if (b > a)
        return (solver(b - a, a));
}