#include <stdio.h>

void main()
{
    int number;
    scanf("%i", &number);

    printf("Signed bit is: %i\n", (number >> ((sizeof(number) * 8) - 1) & 1));
}