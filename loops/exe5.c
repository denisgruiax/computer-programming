#include <stdio.h>

void printSquare(unsigned int l);
void main()
{
    printSquare(10);
}
void printSquare(unsigned int l)
{
    for (size_t i = 1; i <= l; i++)
    {
        for (size_t j = 1; j <= l; j++)
        {
            if ((j == 1) || (j == l) || (i == j))
            {
                printf("* ");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
}
