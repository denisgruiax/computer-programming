#include <ctype.h>
#include <stdio.h>

char isCaracter(char x);
void solve(char text[100]);
void display(char text[100]);

void main()
{
    char text[100];

    printf("Insert the text: ");
    gets(text);

    solve(text);
    display(text);
}

char isCaracter(char x)
{
    if ((x >= 'a') && (x <= 'z'))
        return 1;
    
    if ((x >= 'A') && (x <= 'Z'))
        return 1;

    return 0;
}

void solve(char text[100])
{
    int holder = 1;
    for (unsigned long i = 0; text[i] != '\0'; i++)
    {
        if (isCaracter(text[i]) && holder)
        {
            text[i] = toupper(text[i]);
            holder = 0;
        }

        if (!isCaracter(text[i]) && !holder)
            holder = 1;
    }
}

void display(char text[100])
{
    for (unsigned i = 0; text[i] != '\0'; i++)
        putchar(text[i]);
}