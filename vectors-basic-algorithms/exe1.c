#include <stdio.h>

void main()
{
    int vector[] = {7, -5, 4, 3, -9, 2, -8};

    printf("vector = {");
    for (size_t i = 0; i < sizeof(vector) / sizeof(int); i++)
    {
        if(vector[i] < 0)
        printf("%i ", vector[i]);
    }
    printf("}");
}