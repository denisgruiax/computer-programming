#include <stdio.h>

void main()
{
    int vector[] = {7, -5, 4, 3, -9, 2, -8}, *p = &vector, minim = vector[0];

    for (size_t i = 0; i <(sizeof(vector)/sizeof(int)) ; p++, i++)
    {
        if (*p < minim)
        {
            minim = *p;
        }
    }

    printf("count = %i", minim);
    
}