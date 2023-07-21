#include <stdio.h>

typedef struct
{
    int hour;
    float temperature;
} Temperature;

void read(Temperature vector[], unsigned int numberOfMeasurements);
float media(Temperature vector[], int initialHour, int finalHour, unsigned int numberOfMeasurements);

int main()
{
    unsigned int numberOfMeasurements, initHour, finalHour;

    printf("n = ");
    scanf("%u", &numberOfMeasurements);

    printf("Initial hour: ");
    scanf("%u", &initHour);

    printf("Final hour: ");
    scanf("%u", &finalHour);

    Temperature temperatures[numberOfMeasurements];

    read(temperatures, numberOfMeasurements);
    printf("Media: %0.2f\n", media(temperatures, initHour, finalHour, numberOfMeasurements));

    return 0;
}

void read(Temperature vector[], unsigned int numberOfMeasurements)
{
    for (size_t i = 0; i < numberOfMeasurements; i++)
    {
        printf("Structure %u:\n", i+1);

        printf("hour: ");
        scanf("%i", &vector[i].hour);

        printf("temperature: ");
        scanf("%f", &vector[i].temperature);
        putchar('\n');
    }
}
float media(Temperature vector[], int initialHour, int finalHour, unsigned int numberOfMeasurements)
{
    unsigned int numberOfCases;
    float sumOfTemperatures = 0;
    for (size_t i = 0; i < numberOfMeasurements; i++)
    {
        if ((vector[i].hour >= initialHour) && (vector[i].hour <= finalHour))
        {
            sumOfTemperatures += vector[i].temperature;
            numberOfCases++;
        }
    }

    return (sumOfTemperatures / (float)numberOfCases);
}