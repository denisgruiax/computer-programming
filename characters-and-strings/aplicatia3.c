#include <stdio.h>
#include <string.h>

void read(char input[][30], unsigned short size);
void print(char input[][30], unsigned short int);
int checker(char input[][30], char container[][30], int index);

int main()
{
    char nume[10][30], container[10][30];
    unsigned short n;

    printf("n = ");
    scanf("%hhu", &n);

    getchar();

    read(nume, n);
    print(nume, n);

    for (int i = 0; i < n; i++)
    {
        
        if (checker(nume, container, i))
        {
            int count = 0;

            for (size_t j = i; j < n; j++)
            {
                if (!strcmp(nume[i], nume[j]))
                {
                    count++;
                }
            }

            printf("%s -> %i\n", nume[i], count);
        }
        
    }
    
    return 0;
}

void read(char input[][30], unsigned short size)
{
    for (short int i = 0; i < size; i++)
    {
        printf("text %hhu: ", i);
        gets(input[i]);
    }

    putchar('\n');
}

void print(char input[][30], unsigned short size)
{
    for (size_t i = 0; i < size; i++)
        puts(input[i]);

    putchar('\n');
}

int checker(char input[][30], char container[][30], int index)
{
    static int c1 = 0;
    int flag = 1;

    for (size_t i = 0; i < c1+1; i++)
        if (!strcmp(input[index], container[i]))
        {
            flag = 0;
            return 0;
        }
    if (!flag)
        return 0;
    
    if (flag)
    {
        strcpy(container[c1], input[index]);
        c1++;
    }

    return 1;
}