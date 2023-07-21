#include <stdio.h>

#define max(a, b) ((a > b) ? (a) : (b))
float max3(float a, float b, float c);

void main()
{
    float a, b, c;

    printf("Introduceti pe aceeasi linie 3 valori float: ");
    scanf("%f %f %f", &a, &b, &c);

    printf("max = %f\n", max3(a, b, c));
}

float max3(float a, float b, float c)
{
    return (max(max(a, b), c));
}