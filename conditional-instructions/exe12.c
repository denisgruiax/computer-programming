#include <stdio.h>

void anBisect(unsigned int an)
{
    (((an % 4 == 0) && (an % 100 != 0)) || (an % 400 == 0))?\
     printf("%u este bisect\n", an) : printf("%u nu este bisect\n", an);
}

void anBisect2(unsigned int an)
{
    !((an % 4 != 0) || ((an % 100 == 0) && (an % 400 != 0)))?\
     printf("%u este bisect\n", an) : printf("%u nu este bisect\n", an);
}

void main()
{
    
    anBisect(1800);
    anBisect(4);
    anBisect(1600);
    anBisect(2012);
    anBisect(1700);
    anBisect(2018);
    printf("\n");
    anBisect2(1800);
    anBisect2(4);
    anBisect2(1600);
    anBisect2(2012);
    anBisect2(1700);
    anBisect2(2018);
}