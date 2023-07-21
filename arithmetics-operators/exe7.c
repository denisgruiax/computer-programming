#include <stdio.h>
#include <math.h>

//suma primilor 4 biti (LSB)
void main()
{
    unsigned int suma = 0;
    int numar;
    
    scanf("%i", &numar);

    for (int i = 0; i < 4; i++)
    {
        suma += ((numar >> i) & 1);
    }

    printf("suma = %u", suma);   
}