#include <stdio.h>

int x[30], n, n0; //my vector

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
    scanf("%i", &n0);
    n = 2 * n0;
    int count = 1;
    for (size_t i = 0; i < n; i += 2)
    {
        printf("perechea %i:\n", count);

        printf("poz[%i]: ", i);
        scanf("%i", &x[i]);

        printf("poz[%i]: ", (i + 1));
        scanf("%i", &x[i + 1]);

        printf("\n");

        count++;
    }
}
void printVector()
{
    for (size_t i = 0; i < n; i++)
    {
        printf("%i ", x[i]);
    }
}

int i, j;

void updateVector()
{
    for (i = 0; i <= n; i += 2)
    {
        if (i > 1)
        {
            for (j = n; j > i; j--)
            {
                x[j] = x[j - 1];
            }
            x[i] = x[i - 1] + x[i - 2];
            n++;
            i++;
        }
    }
}
