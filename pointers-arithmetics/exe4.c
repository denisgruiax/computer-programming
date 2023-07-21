#include <stdio.h>

void main()
{
    int vector[] = {7, -5, 4, 3, -9, 2, -8}, *p = &vector;
    unsigned int count;

    for (size_t i = 0; i <(sizeof(vector)/sizeof(int)) ; p++, i++)
    {
        if (*p < 0)
        {
            count++;
        }
    }

    printf("count = %u", count);
    
}