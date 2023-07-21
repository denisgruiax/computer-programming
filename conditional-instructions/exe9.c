#include <stdio.h>

void main()
{
    unsigned a, b, c;

    printf("latura a: ");
    scanf("%u", &a);

    printf("latura b: ");
    scanf("%u", &b);

    printf("latura c: ");
    scanf("%u", &c);

    printf("Triunghiul %s isoscel.\n", ((a == b) | (a == c) | (b == c)) ? "este" : "nu este");
}