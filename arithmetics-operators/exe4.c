#include <stdio.h>

void main()
{
    int a = 5, b = 1, c;
    c = --a - --b;
    printf("%d %d %d\n", a, b, c);
    c = --a + b--;
    printf("%d %d %d\n", a, b, c);
    c = a++ - b++;
    printf("%d %d %d\n", a, b, c);
}