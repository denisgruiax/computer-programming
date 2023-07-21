#include <stdio.h>

void solve(int v[], unsigned int *p, unsigned int *q, unsigned int dimension);

void main()
{
    unsigned int min, max;

    int vector[] = {1, 6, -3333, -4, 8, -9, 0, 1, 3, 5, -7, 21, 12, -123, 1232, -54, 34, 654097};

    solve(vector, &min, &max, sizeof(vector)/sizeof(int));
    printf("min: %u\nmax: %u\n\n", min, max);
}

void solve(int v[], unsigned int *p, unsigned int *q, unsigned int dimension)
{
    int hold1 = v[0], hold2 = v[0];
    for (unsigned int i = 1; i < dimension; i++)
    {
        if (v[i] < hold1)
        {
            *p = i;
            hold1 = v[i];
        }

        if (v[i] > hold2)
        {
            *q = i;
            hold2 = v[i];
        }
    }
}