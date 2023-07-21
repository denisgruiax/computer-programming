#include <stdio.h>

int x[10], n; //my vector

void readVector();
void printVector();
void updateVector();

void main()
{
    readVector();
    updateVector();
    printVector();
}

void readVector()
{
    printf("n = ");
    scanf("%i", &n);

    for (size_t i = 0; i < n; i++)
    {
        printf("x[%i] = ", i);
        scanf("%i", &x[i]);
    }
}
void printVector()
{
    for (size_t i = 0; i < n; i++)
    {
        printf("%i ", x[i]);
    }
}
void updateVector()
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = (i + 1); j < n; j++)
        {
            if (x[j] == x[i])
            {
                for (size_t k = j; k < n; k++)
                {
                    x[j] = x[j+1];
                }
                n--;
            }
        }
    }
}
