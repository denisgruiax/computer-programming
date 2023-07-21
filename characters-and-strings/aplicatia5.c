#include <stdio.h>
#include <string.h>

void read(char input[][30], unsigned int size);
void foo(char dest[], char source[][30], unsigned int size);
void print_v(char vector[]);

int main()
{
    char text[100], nume[10][30];
    unsigned int n;

    printf("n = ");
    scanf("%u", &n);
    getchar();

    read(nume, n);
    foo(text, nume, n);

    puts(text);
}

void read(char input[][30], unsigned int size)
{
    for (unsigned int i = 0; i < size; i++)
    {
        printf("nume %u: ", i);
        gets(input[i]);
    }

    putchar('\n');
}

void foo(char dest[], char source[][30], unsigned int size)
{
    unsigned int i = 0;

    strcpy(dest, source[i]);
    strcat(dest, ", ");

    for (i = 1; i < (size-2); i++)
    {
        strcat(dest, source[i]);
        strcat(dest, ", ");
    }

    strcat(dest, source[i]);
    strcat(dest, " si ");
    strcat(dest, source[i+1]);
    strcat(dest, " invata.");
}