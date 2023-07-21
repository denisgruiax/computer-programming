#include <stdio.h>
#include <string.h>

typedef struct
{
    char nume[50];
    float pret;
} Produs;

int main()
{
    Produs produse[100];
    int i, j, op, n = 0; // initial 0 produse
    char nume[50];

    for (;;)
    {
        printf("1. Introducere\n"); // afisare meniu
        printf("2. Afisare\n");
        printf("3. Sortare\n");
        printf("0. Iesire\n\n");
        printf("operatia: ");
        scanf("%d", &op); // cere operatia
        switch (op)
        {
        case 1:        // introducere produs nou
            
            getchar(); /* consuma \n ramas de la citirea codului de operatie*/
            
            printf("nume: ");
            fgets(nume, 50, stdin);
            nume[strcspn(nume, "\n")] = '\0';

            int exist = 0;
            for (size_t i = 0; i < n; i++)
            {
                if (!strcmp(nume, produse[i].nume))
                {
                    printf("pret: ");
                    scanf("%g", &produse[i].pret);
                    exist = 1;
                }
            }

            if (!exist)
            {
                strcpy(produse[n].nume, nume);
                printf("pret = ");
                scanf("%g", &produse[n].pret);
                n++;
            }

            break;
        case 2: // afisare produse
            for (i = 0; i < n; i++)
            {
                printf("%s %g\n", produse[i].nume, produse[i].pret);
            }
            break;
        case 3:
            printf("\nSortare...\n");

            char tempName[50];
            float tempValue;

            for (i = 0; i < n; i++)
            {
                for (size_t j = 0; j < n; j++)
                {
                    if (strcmp(produse[i].nume, produse[j].nume) < 0)
                    {
                        strcpy(tempName, produse[i].nume);
                        tempValue = produse[i].pret;

                        strcpy(produse[i].nume, produse[j].nume);
                        produse[i].pret = produse[j].pret;

                        strcpy(produse[j].nume, tempName);
                        produse[j].pret = tempValue;
                    }
                }
            }

            printf("\nAfisare...\n");
            for (size_t i = 0; i < n; i++)
            {
                printf("%s %0.2f\n", produse[i].nume, produse[i].pret);
            }

        case 0:
            return 0; // iesire din program
        default:
            printf("operatie necunscuta\n");
        }
    }

    return 0;
}
