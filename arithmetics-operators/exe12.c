#include <stdio.h>

void afisare2(unsigned int x);
unsigned int segmente(unsigned int x);

void main()
{
    unsigned int numar = 4089500123;
    afisare2(numar);
    printf("Sunt %u segmente\n", segmente(numar));
}

void afisare2(unsigned int x)
{
    for (int i = ((sizeof(x) * 8) - 1); i >= 0; i--)
    {
        if ((i < 31) && (i > 0))
            if (((x >> i) & 1) != ((x >> (i + 1)) & 1))
                printf(" ");

        printf("%i", (x >> i) & 1);
    }
    printf("\n");
}

unsigned int segmente(unsigned int x)
{
    unsigned int count = 1;
    for (int i = 31; i > 0; i--)
    {
        if (((x >> i) & 1) != ((x >> (i - 1)) & 1))
        {
            count += 1;
        }
    }
    return count;
}