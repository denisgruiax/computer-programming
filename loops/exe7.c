#include <stdio.h>

void main()
{
    for (size_t i = 0; i < 11; i++, printf("\n"))
    {
        for (size_t j = 0; j < 11; j++)
        {
            printf("%i * %i = %i\n", i, j, i * j);
        }
    }
}