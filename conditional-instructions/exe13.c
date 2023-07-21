#include <stdio.h>

const float constant1 = (212.0 - 32.0) / 100.0;
const float constant2 = (100.0) / (212.0 - 32.0);

void menu(float temperature)
{
    char option;
    printf("1 - grade celsius in farenheit.\n2 - grade farenheit in celsius.\n");
    scanf(" %c", &option);

    switch (option)
    {
    case '1':
        printf("%u°C sunt %.2f°F.\n", temperature, ((constant1 * temperature) + 32.0));
        break;
    case '2':
        printf("%u°F sunt %.2f°C.\n", temperature, (constant2 * (temperature - 32.0)));
        break;
    default:
        printf("Tasta grasita.\n");
        break;
    }
}

void main()
{
    float t;

    // 0°C -> 32°F
    //100°C -> 212°C

    printf("Introduceti temperatura: ");
    scanf("%f", &t);
    menu(t);
}