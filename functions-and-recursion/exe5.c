#include <stdio.h>

void citireVector(float a[], int k);
void afisareVector(float a[], int k);

void citireMatrice(float a[][10], unsigned int m, unsigned int n);
void afisareMatrice(float a[][10], unsigned int m, unsigned int n);

void egal(float a[][10], unsigned int m, unsigned int n, float b[], unsigned int k);

void main()
{
    unsigned int m, n, k;

    printf("m (0 < m < 10) & n (3 < n < 10) & k (0 < k < 5)= ");
    scanf("%u %u %u", &m, &n, &k);

    float matrix[m][n], vector1[k];

    citireVector(vector1, k);
    afisareVector(vector1, k);

    citireMatrice(matrix, m, n);
    afisareMatrice(matrix, m, n);

    egal(matrix, m, n, vector1, k);
}

void citireVector(float a[], int k)
{
    for (float *p = a; k--; p++)
    {
        printf("v[%i] = ", (p - a));
        scanf("%f", p);
    }
}

void afisareVector(float a[], int k)
{
    for (float *p = a; k--; p++)
    {
        printf("%.2f ", *p);
    }
    printf("\n");
}

void citireMatrice(float a[][10], unsigned int m, unsigned int n)
{
    for (unsigned int i = 0; i < m; i++)
        for (unsigned int j = 0; j < n; j++)
        {
            printf("Pozitia (%i, %i): ", i, j);
            scanf("%f", &a[i][j]);
        }
}

void afisareMatrice(float a[][10], unsigned int m, unsigned int n)
{
    for (unsigned int i = 0; i < m; i++, putchar('\n'))
    {
        for (unsigned int j = 0; j < n; j++)
        {
            printf("%.2f ", a[i][j]);
        }
    }
}

void egal(float a[][10], unsigned int m, unsigned int n, float b[], unsigned int k)
{
    int hold = 1;
    for (unsigned int i = 0; i < m; i++)
        for (unsigned int j = 0; j < n; j++)
        {
            for (unsigned int l = j, c = 0; c < k; l++, c++)
                if (a[i][l] != b[c])
                {
                    hold = 0;
                    break;
                }
            if (hold)
                printf("Vectorul apare de la pozitia (%i, %i).\n", i, j);
            else
                hold = 1;
        }
}