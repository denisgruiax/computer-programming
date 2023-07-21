#include <stdio.h>

unsigned int function(int x)
{
    unsigned int count = 0;

    for (int i = 0; i < (sizeof(x) * 8); i++)
    {

        if ((x >> i) & 1)
        {
            count++;
        }
        else
        {
            continue;
        }
    }
    return count;
}

void afisare_biti(int x)
{
    printf("biti: ");
    for (int i = 31; i >= 0; i--)
    {
        printf("%u", (((x) >> i) & 1));
    }
    putchar('\n');
}
void main()
{
    int numar;
    //numerele negative se stocheaza in complement de 2
    //exemplue -7: 1111....111001
    do
    {
        printf("numar = ");
        scanf("%i", &numar);

        afisare_biti(numar);
        printf("numar biti de 1: %u\n\n", function(numar));
    } while (numar != 0);
}