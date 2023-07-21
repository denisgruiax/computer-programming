#include <stdio.h>
#include <string.h>

int main()
{
    unsigned int n, aux = 0, index = 0;

    printf("n = ");
    scanf("%i", &n);

    getchar();

    char nume[n][30];

    for (unsigned int i = 0; i < n; i++)
    {
        printf("Nume %i:", i);
        gets(nume[i]);
    }

    aux = strlen(nume[0]);

    for (unsigned int i = 0; i < n; i++)
    {
        if (strlen(nume[i]) > aux)
        {
            aux = strlen(nume[i]);
            index = i;
        }
    }

    printf("Cel mai lung nume: %s\nNumar litere: %u\n", nume[index], aux);
    
    return 0;
}