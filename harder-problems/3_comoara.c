#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    int x, y;
} Point;

#define key 7
#define max(x, y) ((x >= y) ? (x) : (y))

int gTable[5][5] = {0};
Point gTreasurePoint, gStartPoint;

Point setTreasure(int treasure, unsigned line, unsigned column);
int distance(Point point1, Point point2);
void initTable(int treasure);
void printTable();
void readStartPoint();
int checkPoint(Point curentPoint);
void start(Point startPoint);

int main()
{
    printf("Interval StartPoint for x & y: [1, 5].\n");
    gTreasurePoint = setTreasure(key, 1, 1);

    initTable(key);
    printTable();

    readStartPoint();

    start(gStartPoint);
    return 0;
}

Point setTreasure(int treasure, unsigned line, unsigned column)
{
    Point p;
    p.x = line;
    p.y = column;

    gTable[line][column] = treasure;

    return p;
}

int distance(Point point1, Point point2)
{
    return (max(abs(point1.x - point2.x), abs(point1.y - point2.y)));
}

void initTable(int treasure)
{
    Point curentPoint;

    for (unsigned i = 0; i < 5; i++)
        for (unsigned j = 0; j < 5; j++)
        {
            curentPoint.x = i;
            curentPoint.y = j;

            if (gTable[i][j] != treasure)
                gTable[i][j] = distance(curentPoint, gTreasurePoint);
        }
}

void printTable()
{
    for (unsigned i = 0; i < 5; i++, putchar('\n'))
        for (unsigned j = 0; j < 5; j++)
        {
            printf("%d ", gTable[i][j]);
        }

    putchar('\n');
}

void readStartPoint()
{
startPoint:
    printf("Start point: "),
        scanf("%d %d", &gStartPoint.x, &gStartPoint.y);
        getchar(); //removes the '\n' 

    if ((gStartPoint.x < 1) || (gStartPoint.x > 5))
    {
        printf("Point go out from interval -> x\n");
        goto startPoint;
    }

    if ((gStartPoint.y < 1) || (gStartPoint.y > 5))
    {
        printf("Point go out from interval -> y\n");
        goto startPoint;
    }

    gStartPoint.x--;
    gStartPoint.y--;

    putchar('\n');
}

int checkPoint(Point curentPoint)
{
    if (gTable[curentPoint.x][curentPoint.y] == key)
        return 1;
    return 0;
}

void start(Point startPoint)
{
    if (gTable[startPoint.x][startPoint.y] == key)
    {
        printf("You found the treasure!");
    }

    else
    {
        char option;
        int found = 0;

        printf("You are at (%d, %d)\n", startPoint.x + 1, startPoint.y + 1);
        printf("Distance is %d.\n", distance(startPoint, gTreasurePoint));
        printf("Where you go ? (U-up, D-dowm, L-left, R-right, X-exit)\n\n");

        do
        {
            printf("Insert option: ");
            scanf(" %c", &option);

            switch (option)
            {
            case 'U':
                startPoint.x--;

                if (startPoint.x < 0)
                {
                    startPoint.x++;
                    printf("You can t go lower than 1.\n");
                    printf("The position is the same.\n\n");
                }
                else
                {
                    found = checkPoint(startPoint);

                    if (found)
                    {
                        printf("You found the treasure!\n");
                        option = 'X';
                    }
                    else
                    {
                        printf("You are at (%d, %d)\n", startPoint.x + 1, startPoint.y + 1);
                        printf("Distance is %d.\n", distance(startPoint, gTreasurePoint));
                        printf("Where you go ? (U-up, D-dowm, L-left, R-right, X-exit)\n\n");
                    }
                }

                break;

            case 'D':
                startPoint.x++;

                if (startPoint.x > 4)
                {
                    startPoint.x--;
                    printf("You can t go above 5.\n");
                    printf("The position is the same.\n\n");
                }
                else
                {
                    found = checkPoint(startPoint);

                    if (found)
                    {
                        printf("You found the treasure!\n");
                        option = 'X';
                    }
                    else
                    {
                        printf("You are at (%d, %d)\n", startPoint.x + 1, startPoint.y + 1);
                        printf("Distance is %d.\n", distance(startPoint, gTreasurePoint));
                        printf("Where you go ? (U-up, D-dowm, L-left, R-right, X-exit)\n\n");
                    }
                }

                break;

            case 'L':
                startPoint.y--;

                if (startPoint.y < 0)
                {
                    startPoint.x++;
                    printf("You can t go lower than 1.\n");
                    printf("The position is the same.\n\n");
                }
                else
                {
                    found = checkPoint(startPoint);

                    if (found)
                    {
                        printf("You found the treasure!\n");
                        option = 'X';
                    }
                    else
                    {
                        printf("You are at (%d, %d)\n", startPoint.x + 1, startPoint.y + 1);
                        printf("Distance is %d.\n", distance(startPoint, gTreasurePoint));
                        printf("Where you go ? (U-up, D-dowm, L-left, R-right, X-exit)\n\n");
                    }
                }

                break;

            case 'R':
                startPoint.y++;

                if (startPoint.x > 4)
                {
                    startPoint.y--;
                    printf("You can t go above 5.\n");
                    printf("The position is the same.\n\n");
                }
                else
                {
                    found = checkPoint(startPoint);

                    if (found)
                    {
                        printf("You found the treasure!\n");
                        option = 'X';
                    }
                    else
                    {
                        printf("You are at (%d, %d)\n", startPoint.x + 1, startPoint.y + 1);
                        printf("Distance is %d.\n", distance(startPoint, gTreasurePoint));
                        printf("Where you go ? (U-up, D-dowm, L-left, R-right, X-exit)\n\n");
                    }
                }
                break;

            default:
                printf("Bad option\n");
                break;
            }
        } while ((option != 'X'));
    }
}