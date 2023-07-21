/*n+1			dacă m=0
A(m-1,1)		dacă m>0 și n=0
A(m-1,A(m,n-1))	dacă m>0 și n>0*/

#include <stdio.h>

unsigned long long ackerman(unsigned long long m, unsigned long long n);
unsigned long long acker(unsigned long long m, unsigned long long n);

void main()
{
    unsigned long long hold = acker(3, 10);
    printf("%lld\n", hold);

    unsigned long long hold2 = ackerman(3, 10);
    printf("%lld\n", hold2);
}

unsigned long long ackerman(unsigned long long m, unsigned long long n)
{
    if (!m)
        return (n + 1ULL);
    if (!n)
        return (ackerman(m - 1ULL, 1ULL));
    if ((m > 0) && (n > 0))
        return (ackerman(m - 1ULL, ackerman(m, n - 1ULL)));
}

unsigned long long acker(unsigned long long m, unsigned long long n)
{
    while (1)
        switch (m)
        {
        case 0:
            return n + 1U;
        case 1:
            return n + 2U;
        case 2:
            return 2U * (n + 1U) + 1U;
        case 3:
            return (1LLU << (n + 3U)) - 3U;
        default:
            if (n == 0U)
                n = 1U;
            else
                n = acker(m, n - 1U);
            m--;
            break;
        }
    return n + 1U;
}