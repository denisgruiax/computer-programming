#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159
#define ROT 360.0

unsigned numberOfPeaks_, numberOfPoints;
double xCircle_, yCircle_, circleRadius_;

typedef struct
{
    double x, y;
} Point;

void readValues();
double getRadians(double degrees);
Point calculatePoint(double radius, double radians);
Point calculateFurtherPoint(Point point, double xCenter, double yCenter, double radians);
Point *fillPoints(double xCenter, double yCenter, double radius, double degrees);
void printPoints(Point *points);
void calculateLength(Point point_1, Point point_2);
void printLengths(Point *points, Point center);
Point *transformPoints(Point *points, Point newCenter);
void printSVG(Point *points);
void printLines(Point *points);

int main()
{
    readValues();
    Point center = {0, 0};
    Point newCenter = {xCircle_, yCircle_};
    Point *points = NULL;

    double angle = ROT / numberOfPeaks_;
    double radians = getRadians(angle);

    points = fillPoints(xCircle_, yCircle_, circleRadius_, angle);
    printPoints(points);
    printLengths(points, center);

    points = transformPoints(points, newCenter);
    printPoints(points);
    printLengths(points, newCenter);
    printSVG(points);
    printLines(points);
}

void readValues()
{
    puts("Enter center and radius values:");
    scanf("%lf %lf %lf", &xCircle_, &yCircle_, &circleRadius_);

    puts("Enter number of peaks:");
    scanf("%u", &numberOfPeaks_);
}

double getRadians(double degrees)
{
    return (degrees * (PI / 180.0));
}

Point calculatePoint(double radius, double radians)
{
    Point point;

    point.x = radius * (sin(radians));
    point.y = radius * (cos(radians));

    return point;
}

Point calculateFurtherPoint(Point point, double xCenter, double yCenter, double radians)
{
    Point furtherPoint;

    furtherPoint.x = point.x + xCenter;
    furtherPoint.y = point.y + yCenter;

    return furtherPoint;
}

Point *fillPoints(double xCenter, double yCenter, double radius, double degrees)
{
    Point *points = (Point *)malloc(numberOfPeaks_ * sizeof(Point));

    double curentDegrees = degrees;

    for (unsigned i = 0; i < numberOfPeaks_; i++, curentDegrees += degrees)
    {
        double radians = getRadians(curentDegrees);
        Point point = calculatePoint(radius, radians);

        points[i] = point;
    }

    return points;
}

void printPoints(Point *points)
{
    for (unsigned i = 0; i < numberOfPeaks_; i++)
    {
        printf("(%0.3f, %0.3f)\n", points[i].x, points[i].y);
    }
}

void calculateLength(Point point_1, Point point_2)
{
    double length = sqrt(pow((point_2.x - point_1.x), 2) + (pow((point_2.y - point_1.y), 2)));
    printf("[(%0.3f, %0.3f), (%0.3f, %0.3f)] = %0.3f\n", point_1.x, point_1.y, point_2.x, point_2.y, length);
}

void printLengths(Point *points, Point center)
{
    for (unsigned i = 0; i < numberOfPeaks_; i++)
    {
        calculateLength(center, points[i]);
    }
}

Point *transformPoints(Point *points, Point newCenter)
{
    double angle = ROT / numberOfPeaks_;

    for (unsigned i = 0; i < numberOfPeaks_; i++, angle += angle)
    {
        Point tempPoint = calculateFurtherPoint(points[i], newCenter.x, newCenter.y, getRadians(angle));
        points[i] = tempPoint;
    }

    return points;
}

void printSVG(Point *points)
{
    puts("\n");
    for (size_t i = 0; i < numberOfPeaks_; i++)
    {
        printf("<circle cx=\"%f\" cy=\"%f\" r=\"2\" fill=\"rgb(0,255,0)\" />\n", points[i].x, points[i].y);
    }
}

void printLines(Point *points)
{
    puts("\n");
    for (unsigned i = 1; i < numberOfPeaks_; i++)
    {
        printf("<line x1=\"%f\" y1=\"%f\" x2=\"%f\" y2=\"%f\" style=\"stroke:rgb(0,255,0);stroke-width:2\" />\n", points[i - 1].x, points[i - 1].y, points[i].x, points[i].y);
    }

    printf("<line x1=\"%f\" y1=\"%f\" x2=\"%f\" y2=\"%f\" style=\"stroke:rgb(0,255,0);stroke-width:2\" />\n", points[0].x, points[0].y, points[numberOfPeaks_-1].x, points[numberOfPeaks_-1].y);
}