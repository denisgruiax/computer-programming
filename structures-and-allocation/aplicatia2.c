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
        printf("3.Cautare\n");
        printf("0. Iesire\n");
        printf("operatia: ");
        scanf("%d", &op); // cere operatia
        switch (op)
        {
        case 1:        // introducere produs nou
            getchar(); // consuma \n ramas de la citirea codului de operatie
            printf("nume: ");
            fgets(produse[n].nume, 50, stdin);
            produse[n].nume[strcspn(produse[n].nume, "\n")] = '\0';
            printf("pret: ");
            scanf("%g", &produse[n].pret);
            n++;
            break;
        case 2: // afisare produse
            for (i = 0; i < n; i++)
            {
                printf("%s %g\n", produse[i].nume, produse[i].pret);
            }
            break;
        case 3:
            printf("nume = ");
            scanf("%50s", &nume);

            for (i = 0; i < n; i++)
            {
                if (!strcmp(nume, produse[i].nume))
                {
                    printf("%0.2f\n", produse[i].pret);
                }
            }

        case 0:
            return 0; // iesire din program
        default:
            printf("operatie necunscuta\n");
        }
    }

    return 0;
}
