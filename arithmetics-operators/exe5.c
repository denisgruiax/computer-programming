#include <stdio.h>
#include "myheader.h"

void main()
{
    int t1 = 0, t2 = 0;
    unsigned char a = 0, b = 0;  //variables 'a' and 'b' must be maximum on 4 bits
    unsigned char number = 0; //variable 'number' has maximum 8 bits

    printf("a = ");
    scanf("%i", &t1);

    printf("b = ");
    scanf("%i", &t2); //for unsigned char we could use %hhu but it has some bugs
    
    a |= t1;
    b |= t2;

    number |= a;  //storeing 'a' on the first 4 bits from right
    number <<= 4; //moving the bits 4 times to left to leave space for the 'b' varibale on the first 4 bits from right  
    number |= b;  //storing 'b' on the first 4 bits from right  

    printf("Packed number: %i\n", number); //numberul impachetat

    //unpacking
    int result = 0, result2 = 0;

    result |= (number >> 4);
    number <<= 4;
    number >>= 4;
    result2 |= number;

    printf("a = %i, b = %i\n", result, result2);
}