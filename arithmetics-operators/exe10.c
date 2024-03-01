/* Un nibble este un grup de 4 biti. Să se scrie un program care primește un
număr fără semn n și această funcție
a) returnează valoarea acestui număr cu ordinea inversă a nibble-urilor
b) returnează valoarea acestui număr cu biții din fiecare nibble în ordine
 inversă*/

#include <stdio.h>

void print_bits(unsigned int x);

unsigned int inverseAllNibbles(unsigned int number);

unsigned reverseNibble(unsigned nibble);
unsigned int reverseNibblesBits(unsigned int number);

int main()
{
    unsigned int number = 123473;
    print_bits(number);

    printf("\nInversed nibbles:\n");
    print_bits(inverseAllNibbles(number));

    printf("\nInverse nibbles with reversed bits of nibbles:\n");
    print_bits(reverseNibblesBits(number));

    reverseNibble(7);

    return 0;
}

void print_bits(unsigned int x)
{
    for (int j = 1, i = sizeof(x) * 8 - 1; i >= 0; i--, j++)
    {
        printf("%d", (x >> i) & 1);

        if (j % 4 == 0)
            printf(" ");
    }
    printf("\n");
}

unsigned int inverseAllNibbles(unsigned int number)
{
    unsigned container = 0;

    for (int i = 0; i < 7; i++)
    {
        container |= (number >> 4 * i) & 15;
        container <<= 4;
    }

    return container;
}

unsigned int reverseNibblesBits(unsigned int number)
{
    unsigned container = 0;
    print_bits(container);
    for (int i = 7; i >= 0; i--)
    {
        container |= reverseNibble((number >> 4 * i) & 15);
        if (i > 0)
            container <<= 4;
        print_bits(container);
    }

    return container;
}

unsigned reverseNibble(unsigned nibble)
{
    unsigned container = 0;

    for (int i = 0; i < 4; i++)
    {
        container |= (1 & (nibble >> i));
        if (i < 3)
            container <<= 1;
    }

    return container;
}