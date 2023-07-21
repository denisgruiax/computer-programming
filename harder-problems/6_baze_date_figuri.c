#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define RIGHT 0
#define TOP 90
#define LEFT 180
#define BOTTOM 270 

#define PI 3.14159
#define ROTATION 360.0
#define RADIAN PI / 180

typedef struct
{
    double x, y;
} Point;

typedef struct
{
    Point center;
    Point right;
    Point top;
    Point left;
    Point bottom;
    unsigned radius;
} Circle;

typedef struct
{
    unsigned length, width;
    Point leftBottom;
    Point rightBottom;
    Point topRight;
    Point topLeft;
    Point center;
} Rectangle;

unsigned numberOfRectangles_, numberOfCircles_;

Rectangle *rectangles_;
Circle *circles_;

void rules();
double getRadians(double degrees);
Point calculatePoint(Circle circle, double radians);
int compare(Rectangle rectangle, Circle circle);
Circle calculateCircle();
void printCircle(Circle circle);
void printCircleSVJ(Circle circle);
Rectangle calculateRectangle();
void printRectangle(Rectangle rectangle);
void printRectangleSVJ(Rectangle rectangle);
Circle *addCircle(Circle *circles);
Rectangle *addRectangle(Rectangle *rectangles);
void superFunction(Rectangle *rectangles, Circle *circles);
void menu();

int main()
{
    rules();
    menu();
}

void rules()
{
    puts("1 - Add a circle.");
    puts("2 - Add a rectangle.");
    puts("3 - Prints circles that fits in a rectangle.");
    puts("4 - Exit.\n");
}

double getRadians(double degrees)
{
    return (degrees * (PI / 180.0));
}

Point calculatePoint(Circle circle, double radians)
{
    Point point;

    point.x = circle.center.x + circle.radius * cos(radians);
    point.y = circle.center.y + circle.radius * sin(radians);

    return point;
}

int compare(Rectangle rectangle, Circle circle)
{

    if (circle.right.x <= rectangle.rightBottom.x)
        if (circle.top.y <= rectangle.topRight.y)
            if (circle.left.x >= rectangle.topLeft.x)
                if (circle.bottom.y >= rectangle.leftBottom.y)
                    return 1;
    
    return 0;
}

Circle calculateCircle()
{
    Circle circle;

    printf("center: ");
    scanf("%lf %lf", &circle.center.x, &circle.center.y);

    printf("radius: ");
    scanf("%u", &circle.radius);

    circle.right = calculatePoint(circle, getRadians(RIGHT));
    circle.top = calculatePoint(circle, getRadians(TOP));
    circle.left = calculatePoint(circle, getRadians(LEFT));
    circle.bottom = calculatePoint(circle, getRadians(BOTTOM));

    //printCircle(circle);
    printCircleSVJ(circle);
    getchar();

    return circle;
}

void printCircle(Circle circle)
{
    printf("Circle {%0.2f, %0.2f, %u}, ", circle.center.x, circle.center.y, circle.radius);
    printf("{%0.2f, %0.2f}, {%0.2f, %0.2f}, {%0.2f, %0.2f}, {%0.2f, %0.2f}\n", circle.right.x, circle.right.y,
           circle.top.x, circle.top.y, circle.left.x, circle.left.y, circle.bottom.x, circle.bottom.y);
}

void printCircleSVJ(Circle circle)
{
    printf("<circle cx= \"%f\" cy=\"%f\" r=\"%u\" stroke=\"black\" stroke-width=\"3\" fill=\"red\" />\n", circle.center.x, circle.center.y, circle.radius);
}

Rectangle calculateRectangle()
{
    Point startPoint;
    unsigned length, width;

    printf("Start point: ");
    scanf("%lf %lf", &startPoint.x, &startPoint.y);

    printf("Length & width: ");
    scanf("%u %u", &length, &width);

    getchar();

    Point secondPoint = {startPoint.x + length, startPoint.y};
    Point thirdPoint = {startPoint.x + length, startPoint.y + width};
    Point fourthPoint = {startPoint.x, startPoint.y + width};
    Point center = {(startPoint.x + thirdPoint.x) / 2, (startPoint.y + thirdPoint.y) / 2};

    Rectangle rectangle = {length, width, startPoint, secondPoint, thirdPoint, fourthPoint, center};
    printRectangleSVJ(rectangle);
    return rectangle;
}

void printRectangle(Rectangle rectangle)
{
    printf("Rectangle {%u, %u}, {%0.2f, %0.2f}, {%0.2f, %0.2f}, {%0.2f, %0.2f}, {%0.2f, %0.2f}, {%0.2f, %0.2f}\n", rectangle.length, rectangle.width,
           rectangle.leftBottom.x, rectangle.leftBottom.y, rectangle.rightBottom.x, rectangle.rightBottom.y,
           rectangle.topRight.x, rectangle.topRight.y, rectangle.topLeft.x, rectangle.topLeft.y);
}

void printRectangleSVJ(Rectangle rectangle)
{
    printf("<line x1=\"%f\" y1=\"%f\" x2=\"%f\" y2=\"%f\" style=\"stroke:rgb(0,255,0);stroke-width:2\" />\n", rectangle.leftBottom.x, rectangle.leftBottom.y,
           rectangle.rightBottom.x, rectangle.rightBottom.y);
    printf("<line x1=\"%f\" y1=\"%f\" x2=\"%f\" y2=\"%f\" style=\"stroke:rgb(0,255,0);stroke-width:2\" />\n", rectangle.rightBottom.x, rectangle.rightBottom.y,
           rectangle.topRight.x, rectangle.topRight.y);
    printf("<line x1=\"%f\" y1=\"%f\" x2=\"%f\" y2=\"%f\" style=\"stroke:rgb(0,255,0);stroke-width:2\" />\n", rectangle.topRight.x, rectangle.topRight.y,
           rectangle.topLeft.x, rectangle.topLeft.y);
    printf("<line x1=\"%f\" y1=\"%f\" x2=\"%f\" y2=\"%f\" style=\"stroke:rgb(0,255,0);stroke-width:2\" />\n", rectangle.topLeft.x, rectangle.topLeft.y,
           rectangle.leftBottom.x, rectangle.leftBottom.y);
}
Circle *addCircle(Circle *circles)
{
    Circle circle = calculateCircle();

    numberOfCircles_++;

    circles = (Circle *)realloc(circles, numberOfCircles_ * sizeof(Circle));
    circles[numberOfCircles_ - 1] = circle;

    return circles;
}

Rectangle *addRectangle(Rectangle *rectangles)
{
    Rectangle rectangle;

    numberOfRectangles_++;
    rectangles = (Rectangle *)realloc(rectangles, numberOfRectangles_ * sizeof(Rectangle));

    rectangle = calculateRectangle();
    rectangles[numberOfRectangles_ - 1] = rectangle;

    return rectangles;
}

void superFunction(Rectangle *rectangles, Circle *circles)
{
    for (unsigned i = 0; i < numberOfRectangles_; i++)
    {
        printRectangleSVJ(rectangles[i]);

        for (unsigned j = 0; j < numberOfCircles_; j++)
        {
            if (compare(rectangles[i], circles[j]))
            {
                printCircleSVJ(circles[j]);
            }
        }

        putchar('\n');
    }
    getchar();
}

void menu()
{
    char option;

    do
    {
        printf("Insert option: ");
        option = getchar();

        switch (option)
        {
        case '1':
            circles_ = addCircle(circles_);
            break;

        case '2':
            rectangles_ = addRectangle(rectangles_);
            break;

        case '3':
            superFunction(rectangles_, circles_);
            break;

        case '4':
            printf("Exit loop...\n");
            getchar();
            break;

        default:
            printf("Bad option...\n");
            getchar();
            break;
        }

    } while (option != '4');
}
