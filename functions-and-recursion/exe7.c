#include <stdio.h>
#include <math.h>

#define pi (3.14159265359)
void main()
{
    double x0, y0, x1, y1;
    double panta, val = 180 / pi;

    printf("Introduceti x0, y0, x1, y1 in ordine pe acceasi linie.\n");
    scanf("%lf %lf %lf %lf", &x0, &y0, &x1, &y1);

    panta = (y1 - y0) / (x1 - x0);

    printf("Unghiul dintre Segmentul (%lf, %lf)-(%lf, %lf) si Ox este: %lf\n", x0, y0, x1, y1, atan(panta) * val);
}