#include <stdio.h>
#include <stdlib.h>

unsigned numberOfPoints, sizeOfVector = 1;

typedef struct
{
    int x, y;
} Point;

Point *readPoints(Point *point);
int check(int *p, int key);
int *fillVector(Point *point, int *v);
void foo(Point *point, int *v);

int main()
{
    Point *point = NULL;
    int *vector = NULL;

    printf("Number of points: ");
    scanf("%d", &numberOfPoints);

    point = (Point *)realloc(point, sizeof(Point) * numberOfPoints);

    readPoints(point);
    vector = fillVector(point, vector);
    foo(point, vector);

    return 0;
}

Point *readPoints(Point *point)
{
    unsigned i2 = 1;

    for (Point *i = point; i < &point[numberOfPoints]; i++, i2++)
    {
        printf("Point %d:\n", i2);

        printf("x = ");
        scanf("%d", &i->x);

        printf("y = ");
        scanf("%d", &i->y);

        putchar('\n');
    }

    return point;
}

int check(int *p, int key)
{
    for (unsigned i = 0; i < sizeOfVector; i++)
        if (p[i] == key)
            return 1;

    return 0;
}

int *fillVector(Point *point, int *v)
{
    v = (int *)malloc(sizeof(int));
    v[0] = point->y;

    for (Point *i = point; i < &point[numberOfPoints]; i++)
    {
        if (!check(v, i->y))
        {
            sizeOfVector++;
            v = (int *)realloc(v, sizeof(int) * sizeOfVector);
            v[sizeOfVector - 1] = i->y;
        }
    }

    return v;
}
void foo(Point *point, int *v)
{
    for (unsigned i = 0; i < sizeOfVector; i++)
    {
        printf("For y = %i:\n", *(v+i));
        for (Point *j = point; j < &point[numberOfPoints]; j++)
        {
            if ((j->y) == *(v+i))
                printf("(%i, %i);\n", j->x, j->y);
        }
        putchar('\n');
    }
}