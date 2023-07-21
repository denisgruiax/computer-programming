#include <stdio.h>
#include <math.h>

void main()
{
    unsigned int a, b, c, p;

    printf("latura a: ");
    scanf("%u", &a);

    printf("latura b: ");
    scanf("%u", &b);

    printf("latura c: ");
    scanf("%u", &c);

    p = (a + b + c) / 2; //semi perimetrul

    if (p >= 0)
    {
        printf("Aria aproximativ: %lf\n", sqrt(p*(p-a)*(p-b)*(p-c)));
    }
    else
    {
        printf("Laturile nu formeaza un triunghi.\n");
    }
    
    
}