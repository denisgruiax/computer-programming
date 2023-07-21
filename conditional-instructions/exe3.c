#include <stdio.h>

void menu(float x, float y)
{
    char c;

    printf("1-Maximul dintre x si y\n");7
    printf("2-Minimul dintre x si y\n");
    printf("3-X\n4-Y\n");
    
    do
    {
        printf("Tasta = ");
        scanf(" %c", &c);
        switch (c)
        {
        case '1':
            printf("Max x si y:%f\n", (x > y) ? x : y);
            break;
        case '2':
            printf("Min x si y: %f\n", (x < y) ? x : y);
            break;
        case '3':
            printf("x = %f\n", x);
            break;
        case '4':
            printf("x = %f\n", y);
            break;
        default:
            printf("Tasta incorecta, iesire din program...\n");
            c = 0;
            break;
        }
    } while (c != 0);
}

void main()
{
    float x, y;

    printf("x = ");
    scanf("%f", &x);

    printf("y = ");
    scanf("%f", &y);

    menu(x, y);
}