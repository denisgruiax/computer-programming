#include <stdio.h>
#include <string.h>

int main()
{
    unsigned int number, aux = 0, index = 0;

    printf("number = ");
    scanf("%i", &number);

    getchar();

    char name[number][30];

    for (unsigned int i = 0; i < number; i++)
    {
        printf("Nume %i:", i);
        gets(name[i]);
    }

    aux = strlen(name[0]);

    for (unsigned int i = 0; i < number; i++)
    {
        if (strlen(name[i]) > aux)
        {
            aux = strlen(name[i]);
            index = i;
        }
    }

    printf("Longest name: %s\nNumber of letters: %u\number", name[index], aux);
    
    return 0;
}