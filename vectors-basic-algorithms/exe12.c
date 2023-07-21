#include <stdio.h>

int x[20], n; //my vector

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
        for (size_t j = n; j > i; j--)
        {
            x[j] = x[j - 1];
        }
        x[i + 1] = x[i] * x[i];
        n++;
        i++;
    }
}
