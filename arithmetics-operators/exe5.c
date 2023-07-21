#include <stdio.h>
#include "myheader.h"

void main()
{
    int t1, t2;
    unsigned char a, b;  //deoarece numerele a si b vor fi intotdeauna intre 1 si 9 vor fi pe 4 biti doar
    unsigned char numar; //are doar 8 biti

    printf("a = ");
    scanf("%i", &t1);

    printf("b = ");
    scanf("%i", &t2); //se putea folosi %hhu pente unsigned char dar are bug-uri
    
    a |= t1;
    b |= t2;

    numar |= a;  //stocam pe primii 4 biti numarul a
    numar <<= 4; //mutam cei 4 biti pe pe pozitiile 4 5 6 7
    numar |= b;  //stocam cei 4 biti ai lui b pe primii 4 biti

    //impachetare finalizata

    printf("Numarul impachetat: %i\n", numar); //numarul impachetat

    //dezpachetare
    int rez1 = 0, rez2 = 0;

    rez1 |= (numar >> 4);
    numar <<= 4;
    numar >>= 4;
    rez2 |= numar;

    printf("a = %i, b = %i\n", rez1, rez2);
    //dezpachetare finalizata
}