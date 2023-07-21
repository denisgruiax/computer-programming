#include <stdio.h>

void main()
{
    int binar, octal, decimal, hexazecimal;

    printf("b = ");
    scanf("%i", &binar);
    
    printf("d = ");
    scanf("%i", &decimal);
    
    printf("o = ");
    scanf(" %o", &octal);
    
    printf("x = ");
    scanf("%x", &hexazecimal);

    printf("binar = %i \n", binar); /*doar cifre de 0 si 1*/
    printf("decmal = %i \n", decimal); /*cifre de la 0-9 doar*/
    printf("octal = %o \n", octal); /*cifre de la 0-7 doar*/
    printf("hexazecimal = %x \n", hexazecimal); /*cifre de la 0-9 si letere de la A-F doar*/
}