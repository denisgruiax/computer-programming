#include <ctype.h>
#include <stdio.h>

char isCaracter(char x);
void solve(char sir[100]);
void afisare(char sir[100]);

void main()
{
    char sir[100];

    printf("Introduceti textul: ");
    gets(sir);

    solve(sir);
    afisare(sir);
}

char isCaracter(char x)
{
    if ((x >= 'a') && (x <= 'z'))
        return 1;
    if ((x >= 'A') && (x <= 'Z'))
        return 1;
    return 0;
}

void solve(char sir[100])
{
    int holder = 1;
    for (unsigned long i = 0; sir[i] != '\0'; i++)
    {
        if (isCaracter(sir[i]) && holder)
        {
            sir[i] = toupper(sir[i]);
            holder = 0;
        }

        if (!isCaracter(sir[i]) && !holder)
        {
            holder = 1;
        }
    }
}

void afisare(char sir[100])
{
    for (unsigned i = 0; sir[i] != '\0'; i++)
    {
        putchar(sir[i]);
    }
}