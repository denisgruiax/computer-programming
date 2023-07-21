#include <stdio.h>

void fcn(int n1, int n2);
int v[] = {7, -5, 4, 3, -9, 2, -8}, x, y;
void main()
{
    printf("x = ");
    scanf("%i", &x);

    printf("y = ");
    scanf("%i", &y);

    fcn(x, y);
}

void fcn(int n1, int n2)
{
    int minim = v[0], verify = 0;
    for (size_t i = 0; i < (sizeof(v) / sizeof(int)); i++) 
    {
        if ((v[i] <= minim) && (v[i] < n2) && (v[i] > n1))
        {
            minim = v[i];
            verify = 1;
        }
    }

    verify ? printf("minim intre (%i, %i) = %i\n", n1, n2, minim)
           : printf("nu avem un minim\n");

    /*daca punem un vector ca parametru si utilizam sizeof pe el
va returna 8 bytes*/
}