#include <stdio.h>

void main()
{
    printf("1-Citire\n2-Aisare\n3-Sterge toate valorile egale cu o cifra\n4 - Iesire\n");

    char optiune;
    int a[100], *p, *q, *end = a, n;
    do
    {
        printf("optiune = ");
        scanf(" %c", &optiune);

        switch (optiune)
        {
        case '1':
            for (;;)
            {
                printf("v[%u] = ", (end - a));
                scanf("%i", end);
                if (*end == 0)
                    break;
                end++;
            }
            break;
        case '2':
            for (p = a; p < end; p++)
            {
                printf("%i ", *p);
            }
            printf("\n");

            break;
        case '3':
            printf("n = ");
            scanf("%i", &n);

            for (p = a; p < end; p++)
            {
                if (*p == n)
                {
                    for (q = p; q < end; q++)
                        *q = *(q + 1);
                    end--;
                }
            }
            break;
        case '4':
            printf("Iesire....\n");
            break;

        default:
            printf("Optiunea nu exista...\n");
            break;
        }
    } while (optiune != '4');
}