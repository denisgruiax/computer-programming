#include <stdio.h>

unsigned char vector[32] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                            'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
                            'Y', 'Z', '2', '3', '4', '5', '6', '7'};

void print_bits(unsigned int x);
void function_s(unsigned int number);

void main()
{
    unsigned int number = 4019123981;
    print_bits(number);
    function_s(number);
}

void print_bits(unsigned int x)
{
    for (int i = ((sizeof(x) * 8) - 1); i >= 0; i--)
    {
        if ((i > 0) && ((i+1) % 5 == 0))
            printf(" ");
        printf("%i", (x >> i) & 1);
    }
    printf("\n");
}

void function_s(unsigned int number)
{
    unsigned int store = 0;
    for (int i = 0; i < 7; i++)
    {
        store = 0 | (number & 0b11111);
        number >>= 5;
        printf("number: %u -> %c\n", store, vector[store]);
    }
}
