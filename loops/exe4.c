#include <stdio.h>

void main()
{
    int n;
    printf("Daca introduceti 0 se va termina programul.\n");

    do
    {
        printf("n = ");
        scanf("%i", &n);

        (n < 0) ? printf("eroare.\n") : \
        ((n % 2 == 0) ? (printf("par\n")) : printf("impar\n"));

    } while (n != 0);
}