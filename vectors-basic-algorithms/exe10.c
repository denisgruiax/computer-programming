#include <stdio.h>

int x[10], n; //my vector

void readVector();
void printVector(int n);
void updateVector(int n);

void main()
{
    readVector();
    updateVector(n);
    printVector(n);
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

void printVector(int count)
{
    for (size_t i = 0; i < count; i++)
    {
        printf("%i ", x[i]);
    }
}
int i, j, temp;
void updateVector(int count)
{
    for (i = 0; i < count; i++)
    {
        if (x[i] < 0)
        {
            for (j = (n-1); j > i; j--)
            {
                if (x[j] >= 0)
                {
                    temp = x[i];
                    x[i] = x[j];
                    x[j] = temp;
                    break;
                }
                
            }
            
        }
        
    }
    
}
