#include <stdio.h>

void main()
{
    unsigned int n = 19308, sum = 0;

    while (n > 0) //cu unsigned char nu folosim decremntari pana la 0, ne da eroare, schimbam in marime cu semn!
    {
        printf("%u ", n);
        sum+=n;
        n--;
    }

    printf(" = %u\n", sum);
}