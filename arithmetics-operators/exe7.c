#include <stdio.h>
#include <math.h>

//sum of the first 4 bits (LSB)
void main()
{
    unsigned int sum = 0;
    int number;
    
    scanf("%i", &number);

    for (int i = 0; i < 4; i++)
        sum += ((number >> i) & 1);

    printf("sum = %u", sum);   
}