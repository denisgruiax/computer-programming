#include <stdio.h>

void drawHorizontal(unsigned short n);
void drawVertical(unsigned short n);

void main()
{
    unsigned int n;

    printf("n (n > 4 && n = impar) = ");
    scanf("%u", &n);

    drawHorizontal(n);
    drawVertical(n);
    drawHorizontal(n);
    drawVertical(n);
    drawHorizontal(n);
}

void drawHorizontal(unsigned short n)
{
    printf(" ");
    for (unsigned int i = 0; i < n; i++)
    {
        printf("*");
    }
    
    printf("\n");
}
void drawVertical(unsigned short n)
{
    for (unsigned int i = 0; i < n; i++)
    {
        printf("*");

        for (unsigned int j = 0; j < n; j++)
        {
            printf(" ");
        }
        
        printf("*\n");
    }
}