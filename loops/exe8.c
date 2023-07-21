#include <stdio.h>

void print_b(unsigned int x);
unsigned int nr_biti1(unsigned int x);
unsigned int nr_biti01_10(unsigned int x);
unsigned int bitiPosPara(void);

void main(void)
{
    unsigned int n;

    n = bitiPosPara();
    print_b(n);
    printf("Numar de bitit %u\n", nr_biti1(n));
    printf("Numar de perechi diferite %u\n", nr_biti01_10(n));
}

void print_b(unsigned int x)
{
    for (int i = ((sizeof(x) * 8) - 1); i >= 0; i--)
    {
        printf("%u", (x >> i) & 1);
    }

    printf("\n");
}

unsigned int nr_biti1(unsigned int x)
{
    unsigned int count = 0;
    for (size_t i = 0; i < 32; i++)
    {
        count += ((x >> i) & 1);
    }

    return count;
}
unsigned int nr_biti01_10(unsigned int x)
{
    unsigned int count = 0;
    for (size_t i = 0; i < 31; i++)
    {
        if (((x >> i) & 1) != ((x >> (i + 1)) & 1))
        {
            count += 1;
        }
    }
    return count;
}

unsigned int bitiPosPara(void)
{
    unsigned int x = 0;
    for (size_t i = 0; i < 32; i++)
    {
        if (i % 2 == 1)
        {
            x |= (1 << i);
        }
    }
    return x;
}