#include <stdio.h>
#include <string.h>

char isCaracter(char x);
int checker(char container[], char x);

int main()
{
    char text[100], container[26];
    int count;

    gets(text);

    for (unsigned int i = 0; i < strlen(text); i++)
    {
        count = 0;
        if (checker(container, text[i]) && isCaracter(text[i]))
        {
            for (unsigned j = 0; j < strlen(text); j++)
            {
                if (text[j] == text[i])
                {
                    count++;
                }
            }
            printf("%c -> %u\n", text[i], count);
        }
        else
            continue;
    }

    return 0;
}

char isCaracter(char x)
{
    if ((x >= 'a') && (x <= 'z'))
        return 1;
    if ((x >= 'A') && (x <= 'Z'))
        return 1;
    return 0;
}

int checker(char container[], char x)
{
    static int count2 = 0;
    for (unsigned int i = 0; i < strlen(container); i++)
    {
        if (x == container[i])
        {
            return 0;
        }
    }

    container[count2] = x;
    count2++;

    return 1;
}