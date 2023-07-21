#include <stdio.h>
#include <string.h>

float totalQuantity[10], totalPrice[10];

void read(char produs[][30], float cantitate[], float pret[], unsigned int size);
void print(char produs[][30], float cantitate[], float pret[], unsigned int size);
unsigned int saver(char container[][30], char produs[][30], unsigned int size);
void calculate(char container[][30], char produs[][30], float cantitate[], float pret[], unsigned int size, unsigned int size2);
void finalPrint(char container[][30], float cantitate[], float pret_t[], unsigned int x);

int main()
{
    char produs[10][30], container[10][30];
    float cantitate[10], pret[10];
    unsigned int n;

    printf("n = ");
    scanf("%u", &n);
    getchar();

    read(produs, cantitate, pret, n);
    print(produs, cantitate, pret, n);
    
    puts("\n");

    unsigned int size = saver(container, produs, n);
    
    calculate(container, produs, cantitate, pret, size, n);
    finalPrint(container, totalQuantity, totalPrice, size);
}

void read(char produs[10][30], float cantitate[10], float pret[10], unsigned int size)
{
    for (unsigned int i = 0; i < size; i++)
    {
        printf("produs: ");
        gets(produs[i]);

        printf("cantitate: ");
        scanf("%f", &cantitate[i]);
        getchar();

        printf("pret: ");
        scanf("%f", &pret[i]);
        getchar();
    }
}
void print(char produs[][30], float cantitate[], float pret[], unsigned int size)
{
    for (unsigned int i = 0; i < size; i++)
    {
        printf("%s\t", produs[i]);
        printf("%f\t", cantitate[i]);
        printf("%f\n", pret[i]);
    }
}

unsigned int saver(char container[][30], char produs[][30], unsigned int size)
{
    int flag = 1, c1 = 0;
    for (unsigned int i = 0; i < size; i++)
    {
        flag = 1;
        for (unsigned int j = (i + 1); j < size; j++)
        {
            if (!strcmp(produs[i], produs[j]))
            {
                flag = 0;
                break;
            }
        }

        if (flag)
        {
            strcpy(container[c1], produs[i]);
            c1++;
        }
    }

    return c1;
}

void calculate(char container[][30], char produs[][30], float cantitate[], float pret[], unsigned int size, unsigned int size2)
{
    for (unsigned int i = 0; i < size; i++)
    {
        for (unsigned int j = 0; j < size2; j++)
            if (!strcmp(container[i], produs[j]))
            {
                totalQuantity[i] += cantitate[j];
                totalPrice[i] += pret[j] * cantitate[j];
            }
    }
}

void finalPrint(char container[][30], float cantitate[], float pret_t[], unsigned int x)
{
    float globalPrice = 0;

    printf("produs\tcantitate\tpret\n");

    for (size_t i = 0; i < x; i++)
    {
        printf("%s %.2f %.2f\n", container[i], cantitate[i], pret_t[i]);
        globalPrice += pret_t[i];
    }

    printf("Pret Global: %.2f\n", globalPrice);
}