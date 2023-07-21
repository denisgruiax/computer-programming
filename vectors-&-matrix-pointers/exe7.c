/* 
Se citește un număr n<=10 de orașe și apoi pentru fiecare 2 orașe se citește distanța directă dintre ele. 
Dacă distanța este 0, înseamnă că între acele orașe nu există drum direct. 
Să se afișeze perechea de orașe cele mai apropiate între ele în mod direct.
*/

#include <stdio.h>

void main()
{
    unsigned int n;

    printf("n = ");
    scanf("%u", &n);

    unsigned int v[n*n][3], orase[n], count = 0;

    for (size_t i = 0; i < n; i++)
    {
        printf("oarsul = ");
        scanf("%i", &orase[i]);
    }

    for (size_t i = 0; i < (n - 1); i++)
    {
        for (size_t j = (i + 1); j < n; j++)
        {
            printf("Distanta dintre %u si %u: ", i, j);
            v[count][0] = i;
            v[count][1] = j;
            scanf("%u", &v[count][2]);
            count++;
        }
    }

    printf("\n\n");
    
    for (size_t i = 0; i < count; i++)
    {
        printf("Distanta dintre %u si %u este %u.\n", v[i][0], v[i][1], v[i][2]);
    }

    printf("\n\n");

    unsigned int smallest_d = __UINT32_MAX__;

    for (size_t i = 0; i < count; i++)
    {
        if (v[i][2] < smallest_d)
        {
            smallest_d = v[i][2];
        }
    }

    printf("Cea mai mica distanta intre 2 orase este: %u\n", smallest_d); 
    
    //! Incearca sa accesezi prin adresa unui pointer si orasele, pentru a le afisa.
}