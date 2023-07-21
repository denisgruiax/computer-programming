#include <stdio.h>

void main()
{
    float pret_t, pret_in, pret_out, consumIn, consumOut;
    unsigned int km_in, km_out;
    const float pretLitru = 6.2, consumInMediu = 6.5, consumOutMediu = 5.0;

    printf("Km parcursi in oras: ");
    scanf("%u", &km_in);

    printf("Km parcursi in afara: ");
    scanf("%u", &km_out);

    consumIn = (km_in * consumInMediu) / 100;
    consumOut = (km_out * consumOutMediu) / 100;

    pret_in = consumIn * pretLitru;
    pret_out = consumOut * pretLitru;
    pret_t = pret_in + pret_out;
    printf("Pret total: %f\n", pret_t);
}