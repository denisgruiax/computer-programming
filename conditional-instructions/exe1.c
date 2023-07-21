#include <stdio.h>

void main()
{
    float x, y;
    const unsigned int pretMereKg = 5, pretPereKg= 7, buget = 20;

    printf("Introduceti cantitatea in kg a merelor (valoare reala): ");
    scanf("%f", &x);

    printf("Introduceti cantitatea in kg a perelor (valoare reala): ");
    scanf("%f", &y);

    float suma = ((pretMereKg * x) +(pretPereKg *y));
    if (suma < buget)
    {
        printf("Bani suficienti, rest: %.2f lei\n", ((float)buget - suma));
    }
    else
    {
        printf("Bani insuficienti, mai aveti nevoie de %.2f lei\n", (-(float)buget + suma));
    }
    
    


}