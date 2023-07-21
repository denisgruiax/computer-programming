#include <stdio.h>

void main()
{
    int vector[] = {7, -5, 4, 3, -9, 2, -8}, minim = vector[1];

    printf("minim = {");
    for (size_t i = 0; i < sizeof(vector) / sizeof(int); i++)
    {
        if (vector[i] < minim)
            minim = vector[i];
    }
    printf("%i}", minim);
}