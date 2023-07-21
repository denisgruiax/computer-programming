#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

unsigned gNumberOfDays[12] = {31, 28, 31, 30, 30, 30, 31, 31, 30, 31, 30, 31};
int gMonth[7][7];

const char DAYS[7][15] = {{"Monday"}, {"Tuesday"}, {"Wednesday"}, {"Thursday"}, {"Friday"}, {"Saturday"}, {"Sunday"}};
const char MONTHS[12][15] = {{"January"}, {"February"}, {"March"}, {"April"}, {"May"}, {"June"}, {"July"}, {"August"}, {"September"}, {"October"}, {"November"}, {"December"}};
const unsigned BISECT = 29;
const unsigned NOTBISECT = 28;

int checkYear(unsigned year);
void foo(char day, unsigned month, unsigned year);
void printVector(int vector[][7]);

int main()
{
    unsigned day, month, year;

    printf("Insert numbers on the same line like this: 'day' 'month' 'year': ");
    scanf("%u %u %u", &day, &month, &year);

    printf("\n%s %s %u\n\n", DAYS[day - 1], MONTHS[month - 1], year);
    foo(day, month, year);
    printVector(gMonth);

    return 0;
}

int checkYear(unsigned year)
{
    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
        return true;

    return false;
}

void foo(char day, unsigned month, unsigned year)
{
    int line = (day - 1), column = 1;

    if (checkYear(year))
        gNumberOfDays[1] = BISECT;
    else
        gNumberOfDays[1] = NOTBISECT;

    for (int pos = 1; pos <= gNumberOfDays[month]; pos++, line++)
    {
        if (line == 7)
        {
            line = 0;
            column++;
        }

        gMonth[line][column] = pos;
    }
}

void printVector(int vector[][7])
{
    const char DAYS2[7][4] = {{"Mon"}, {"Tus"}, {"Wed"}, {"Thu"}, {"Fri"}, {"Sat"}, {"Sun"}};
    for (unsigned i = 0; i < 7; i++, putchar('\n'))
    {
        printf("%s ", DAYS2[i]);

        for (unsigned j = 1; j < 7; j++)
        {
            if (gMonth[i][j] != 0)
                printf("%i ", gMonth[i][j]);
            else
                printf(" ");
        }
    }
}