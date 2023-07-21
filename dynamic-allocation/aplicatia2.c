#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char store;

char *line();
char **matrix();
char **sortMatrix(char **matrix, unsigned int n);
void afisare(char **matrix, unsigned int n);

int main()
{
    char **matrix2 = matrix();
    matrix2 = sortMatrix(matrix2, store);
    afisare(matrix2, store);

    free(matrix2);
    for (size_t i = 0; i < store; i++)
    {
        free(matrix2[i]);
    }

    return 0;
}

char *line()
{
    char ch, *pointer = NULL;
    unsigned int numberOfOctets = 0;

    for (;;)
    {
        numberOfOctets++;
        if (!(pointer = (char *)realloc(pointer, numberOfOctets * sizeof(char))))
        {
            free(pointer);
            puts("eroare");
            exit(EXIT_FAILURE);
        }

        ch = getchar();
        if (ch == '\n')
            break;

        pointer[numberOfOctets - 1] = ch;
    }

    pointer[numberOfOctets - 1] = '\0';

    return pointer;
}

char **matrix()
{
    char **holder = NULL;

    unsigned int numberOfLines = 0;

    for (;;)
    {
        numberOfLines++;
        if ((holder = (char **)realloc(holder, numberOfLines * sizeof(char *))) == NULL)
        {
            for (size_t j = 0; j < numberOfLines; j++)
                free(holder[j]);

            free(holder);

            printf("eroare..");
            exit(EXIT_FAILURE);
        }

        holder[numberOfLines - 1] = line();
        if (!strlen(holder[numberOfLines - 1]))
            break;
    }

    store = numberOfLines;

    return holder;
}

char **sortMatrix(char **matrix, unsigned int n)
{
    char temp[100];
    for (unsigned int i = 0; i < (n - 2); i++)
        for (unsigned int j = 0; j < (n - 2); j++) //!scadem -2 (odata pentru memria in plus si odata pentru sirul vid)
        {
            if (strcmp(matrix[j], matrix[j + 1]) > 0)
            {
                strcpy(temp, matrix[j]);
                strcpy(matrix[j], matrix[j + 1]);
                strcpy(matrix[j + 1], temp);
            }
        }

    return matrix;
}

void afisare(char **matrix, unsigned int n)
{
    printf("\nSortare...\n");
    for (size_t i = 0; i < (n - 1); i++)
    {
        printf("%s\n", matrix[i]);
    }
}