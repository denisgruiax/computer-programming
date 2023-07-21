#include <stdio.h>

void main()
{
    int numar;
    scanf("%i", &numar);

    printf("bitul de semn: %i", (numar >> ((sizeof(numar) * 8) - 1) & 1));
}