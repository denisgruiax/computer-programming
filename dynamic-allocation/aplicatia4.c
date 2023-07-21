#include <stdio.h>
#include <stdlib.h>

unsigned int *pointer;

int *foo();
void printVector();

int main()
{
    int *vector = foo();
    printVector(vector, *pointer);

    free(vector);
    return 0;
}

int *foo()
{
    int *vector = NULL, holder;
    static unsigned int numberOfElements = 0;

    pointer = &numberOfElements;

    for (;;)
    {
        printf("v[%u] = ", numberOfElements);
        scanf("%i", &holder);

        if (!holder)
            break;
        else
        {
            numberOfElements++;
            vector = (int *)realloc(vector, numberOfElements * sizeof(int));
            if (!vector)
            {
                free(vector);
                printf("eroare..");
                exit(EXIT_FAILURE);
            }

            vector[numberOfElements - 1] = holder;
        }
    }

    return vector;
}

void printVector(int *vector, unsigned int sizeOfVector)
{
    for (int i = (sizeOfVector - 1); i >= 0; i--)
    {
        printf("%i ", vector[i]);
    }
}