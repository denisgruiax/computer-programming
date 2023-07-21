#include <stdio.h>
#include <stdlib.h>

unsigned numberOfPersons;

typedef struct
{
    char *name;
    unsigned age;
} Table;

char *readName();
Table *readPeople(Table *person);
Table *modifyName(Table *person, char *name);
void printTable(Table *person);

int main()
{
    Table *person = NULL;
    char name[20];

    person = readPeople(person);

    printf("\nInsert one name: ");
    scanf("%20s", name);
    printf("\n");

    modifyName(person, name);
    printTable(person);
}

char *readName()
{
    char *name = NULL, character;

    for (unsigned numberOfCharacters = 1;; numberOfCharacters++)
    {
        name = (char *)realloc(name, sizeof(char) * numberOfCharacters);
        if (!name)
        {
            puts("error...");
            free(name);
            exit(EXIT_FAILURE);
        }

        character = getchar();
        if ((character == '\n'))
        {
            name[numberOfCharacters - 1] = '\0';
            break;
        }
        else
        {
            name[numberOfCharacters - 1] = character;
        }
    }

    return name;
}

Table *readPeople(Table *person)
{
    char *name = NULL;

    for (;;)
    {
        printf("name: ");
        name = readName();

        if (strlen(name) > 1)
        {
            numberOfPersons++;
            person = (Table *)realloc(person, sizeof(Table) * numberOfPersons);

            person[numberOfPersons - 1].name = NULL;
            person[numberOfPersons - 1].name = (char *)malloc(sizeof(char) * strlen(name));
            if (!(person[numberOfPersons - 1].name))
            {
                puts("error...");
                free(person[numberOfPersons - 1].name);
                exit(EXIT_FAILURE);
            }

            strcpy(person[numberOfPersons - 1].name, name);

            printf("age: ");
            scanf("%u", &person[numberOfPersons - 1].age);
            getchar();
        }
        else
            break;
    }

    return person;
}

Table *modifyName(Table *person, char *name)
{
    char holder[20];
    for (Table *i = person; i < &person[numberOfPersons]; i++)
    {
        if (!(strcmp(i->name, name)))
        {
            strcpy(holder, i->name);
            holder[0] = toupper(holder[0]);
            strcpy(i->name, holder);
        }
    }

    return person;
}

void printTable(Table *person)
{
    printf("name\tage\n");
    for (Table *i = person; i < &person[numberOfPersons]; i++)
    {
        printf("%s\t%u\n", i->name, i->age);
    }
}