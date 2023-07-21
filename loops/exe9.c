#include <stdio.h>

void menu(float x, float y);
void menu_f();

void main()
{
    menu_f();
}

void menu(float x, float y)
{
    char optiune;
    printf("1-Adunare\n");
    printf("2-Scadere\n");
    printf("3-Inmultimre\n");
    printf("4-Impartire\n");
    printf("5-Terminare\n");
    do
    {
        printf("\noptiune: ");
        scanf(" %c", &optiune);

        switch (optiune)
        {
        case '1':
            printf("%.3f + %.3f = %.3f\n", x, y, (x + y));
            break;
        case '2':
            printf("%.3f - %.3f = %.3f\n", x, y, (x - y));
            break;
        case '3':
            printf("%.3f * %.3f = %.3f\n", x, y, (x * y));
            break;
        case '4':
            printf("%.3f / %.3f = %.3f\n", x, y, (x / y));
            break;
        case '5':
            printf("Terminare...\n");
            break;
        }
    } while (optiune != '5');
}

void menu_f()
{
    int x, y;
    char optiune2;
    printf("x = ");
    scanf("%i", &x);

    printf("y = ");
    scanf("%i", &y);

    printf("Doriti sa efectuati in ordinea introdcucerii operatiile? \
    (1 sau 0),\npentru optiunea 0 se inverseaza valoriile\n");

    printf("optiune = ");
    scanf(" %c", &optiune2);

    if (optiune2 == '0')
    {
        menu(y, x);
    }
    else
    {
        menu(x, y);
    }
}