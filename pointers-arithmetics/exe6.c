// varianta cu pointeri
#include <stdio.h>

int main()
{
    int v[10];
    int *end, *p, *q;
    int tmp;
    end = v; // end pointeaza la prima pozitie libera din vector
    for (;;)
    {                              // bucla infinita pentru citire
        printf("v[%d]=", end - v); // nr de elemente deja introduse in vector
        scanf("%d", end);          // citeste direct in vector, dar nu va considera valoarea decat deca este !=0
        if (*end == 0)
            break; // daca s-a introdus 0, iesire din bucla
        end++;     // trece la urmatoarea adresa
    }
    for (p = v; p < end; p++)
        for (q = end; q > v; q--)
            if (*q > *(q - 1))
            { // inversare valori
                tmp = *q;
                *q = *(q-1);
                *(q-1) = tmp;
            }
    for (p = v; p < end; p++)
    { // afisare valori
        printf("%d ", *p);
    }
    return 0;
}
