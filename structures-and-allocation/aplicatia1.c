#include <stdio.h>
#include <math.h>

typedef struct
{
    float x, y;
} Point;

void readPoint(Point acces[], unsigned int numberOfElements);
float distance(float xA, float yA, float xB, float yB);
float foo(Point acces[], unsigned int numberOfElements);

int main()
{
    unsigned int n = 0;

    printf("n = ");
    scanf("%u", &n);

    Point points[n];

    readPoint(points, n);
    printf("max distance: %f\n", foo(points, n));

    return 0;
}

void readPoint(Point acces[], unsigned int numberOfElements)
{
    for (size_t i = 0; i < numberOfElements; i++)
    {
        printf("Point %u: ", i);
        scanf("%f %f", &acces[i].x, &acces[i].y);
    }
}

float distance(float xA, float yA, float xB, float yB)
{
    return (sqrt(pow((xB - xA), 2.0) + (pow((yB - yA), 2.0))));
}

float foo(Point acces[], unsigned int numberOfElements)
{
    float max = distance(acces[0].x, acces[0].y, acces[1].x, acces[1].y);
    float holder = 0;

    for (size_t i = 0; i < numberOfElements; i++)
        for (size_t j = (i + 1); j < numberOfElements; j++)
        {
            holder = distance(acces[i].x, acces[i].y, acces[j].x, acces[j].y);
            max = ((max > holder) ? max : holder);
        }

    return max;
}