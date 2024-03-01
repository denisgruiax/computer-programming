#include <stdio.h>

unsigned int count_bits_of_one(int x)
{
    unsigned int count = 0;

    for (int i = 0; i < (sizeof(x) * 8); i++)
        if ((x >> i) & 1)
            count++;
        else
            continue;

    return count;
}

void print_bits(int x)
{
    printf("biti: ");
    for (int i = 31; i >= 0; i--)
        printf("%u", (((x) >> i) & 1));

    putchar('\n');
}

void main()
{
    int number;
    //negative numbers are stored in complement of 2
    //example for -7: 1111....111001
    do
    {
        printf("number = ");
        scanf("%i", &number);

        print_bits(number);
        printf("count bits of 1: %u\n\n", count_bits_of_one(number));
    } while (number != 0);
}