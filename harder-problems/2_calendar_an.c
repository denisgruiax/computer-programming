#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

unsigned gNumberOfDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int gMonth[7][6];
int gYear[12][7][6];

const char DAYS[7][15] = {{"Monday"}, {"Tuesday"}, {"Wednesday"}, {"Thursday"}, {"Friday"}, {"Saturday"}, {"Sunday"}};
const char MONTHS[12][15] = {{"January"}, {"February"}, {"March"}, {"April"}, {"May"}, {"June"}, {"July"}, {"August"}, {"September"}, {"October"}, {"November"}, {"December"}};

const unsigned BISECT = 29;
const unsigned NOTBISECT = 28;

int checkYear(unsigned year);
void createMonth(unsigned day, unsigned month, unsigned year);
void createYear(unsigned day, unsigned year);
void printMonth(int vector[][6]);
void printYear(int vector[12][7][6]);

int main()
{
    unsigned day, month, year;

    printf("Insert numbers and follow the format: 'day' 'month' 'year': ");
    scanf("%u %u %u", &day, &month, &year);

    printf("\n%s %s %u\n\n", DAYS[day - 1], MONTHS[month - 1], year);
    createMonth(day, month, year);
    printMonth(gMonth);

    printf("\nInsert numbers and follow the format: 'day' year': "); 
    scanf("%u %u", &day, &year);
    
    printf("\nStart day of the year %u is %u\n\n", year, day);
    
    createYear(day, year);
    printYear(gYear);

    return 0;
}

int checkYear(unsigned year)
{
    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
        return true;

    return false;
}

void createMonth(unsigned day, unsigned month, unsigned year)
{
    int line = (day - 1), column = 0;

    if (checkYear(year))
        gNumberOfDays[1] = BISECT;
    else
        gNumberOfDays[1] = NOTBISECT;

    for (int pos = 1; pos <= gNumberOfDays[month-1]; pos++, line++)
    {
        if (line == 7)
        {
            line = 0;
            column++;
        }

        gMonth[line][column] = pos;
    }
}
void createYear(unsigned day, unsigned year)
{
    if (checkYear(year))
        gNumberOfDays[1] = BISECT;
    else
        gNumberOfDays[1] = NOTBISECT;

    int line = (day - 1), column = 0;

    for (int month = 0; month < 12; month++)
    {
        column = 0;
        for (int day = 1; day <= gNumberOfDays[month]; day++, line++)
        {
            if (line == 7)
            {
                line = 0;
                column++;
            }

            gYear[month][line][column] = day;
        }
    }
}

void printMonth(int vector[][6])
{
    const char DAYS2[7][4] = {{"Mon"}, {"Tus"}, {"Wed"}, {"Thu"}, {"Fri"}, {"Sat"}, {"Sun"}};
    for (unsigned i = 0; i < 7; i++, putchar('\n'))
    {
        printf("%s ", DAYS2[i]);

        for (unsigned j = 0; j < 6; j++)
        {
            if (gMonth[i][j] != 0)
                printf("%d ", gMonth[i][j]);
            else
                printf(" ");
        }
    }
}

void printYear(int vector[12][7][6])
{
    const char DAYS2[7][4] = {{"Mon"}, {"Tus"}, {"Wed"}, {"Thu"}, {"Fri"}, {"Sat"}, {"Sun"}};

    for (unsigned month = 0; month < 12; month++)
    {
        printf("%s\n", MONTHS[month]);
        for (unsigned line = 0; line < 7; line++, putchar('\n'))
        {
            printf("%s ", DAYS2[line]);
            for (unsigned column = 0; column < 6; column++)
            {
                if (vector[month][line][column] != 0)
                    printf("%d ", vector[month][line][column]);
                else
                    printf(" ");
            }
        }
        puts("\n");
    }
}