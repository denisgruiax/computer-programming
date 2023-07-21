#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

unsigned numberOfLines;

typedef struct
{
    char *name;
    unsigned numberOfAparition;
} Table;

int isLetter(char letter);
char *readText();
int isThere(Table *name, char *word, unsigned numberOfLines);
Table *storeWords(Table *name, char *text);
void printTable(Table *name, unsigned numberOfLines);

int main()
{
    char *text = NULL;
    Table *table = NULL;

    text = readText();
    table = storeWords(table, text);
    printTable(table, numberOfLines);

    free(text);
    free(table);
    return 0;
}

int isLetter(char letter)
{
    if ((letter >= 65) && (letter <= 90))
        return 1;

    if ((letter >= 97) && (letter <= 122))
        return 1;

    return 0;
}

char *readText()
{
    char *text = NULL, character;
    unsigned int numberOfCharacters;

    for (numberOfCharacters = 1;; numberOfCharacters++)
    {
        if (!(text = (char *)realloc(text, sizeof(char) * numberOfCharacters)))
        {
            free(text);
            puts("error on allocation...");
            exit(EXIT_FAILURE);
        }

        character = getchar();
        if (character == '\n')
        {
            text[numberOfCharacters - 1] = '\0';
            break;
        }
        else
        {
            text[numberOfCharacters - 1] = character;
        }
    }

    return text;
}

int isThere(Table *name, char *word, unsigned numberOfLines)
{
    if (numberOfLines)
        for (Table *i = name; i < &name[numberOfLines]; i++)
        {
            if (!(strcmp(i->name, word)))
            {
                i->numberOfAparition++;
                return 1;
            }
        }

    return 0;
}

Table *storeWords(Table *name, char *text)
{
    char *word = NULL;
    unsigned numberOfCharacters = 0;

    for (unsigned i = 0; i <= strlen(text); i++)
    {
        if (isLetter(text[i]))
        {
            numberOfCharacters++;
            word = (char *)realloc(word, sizeof(char) * numberOfCharacters);

            if (!word)
            {
                free(word);
                puts("error");
                exit(EXIT_FAILURE);
            }

            word[numberOfCharacters - 1] = text[i];
        }
        else
        {
            if (word)

                if (strlen(word) > 1)

                    if (!(isThere(name, word, numberOfLines)))
                    {
                        numberOfLines++;
                        name = (Table *)realloc(name, sizeof(Table) * numberOfLines);
                        if (!(name))
                        {
                            free(name);
                            puts("error...");
                            exit(EXIT_FAILURE);
                        }

                        name[numberOfLines - 1].name = NULL;
                        name[numberOfLines - 1].name = (char *)realloc(name[numberOfLines - 1].name, sizeof(char) * strlen(word));

                        if (!(name[numberOfLines - 1].name))
                        {
                            free(name[numberOfLines - 1].name);
                            puts("error...");
                            exit(EXIT_FAILURE);
                        }

                        strcpy(name[numberOfLines - 1].name, word);

                        name[numberOfLines - 1].numberOfAparition = 1;
                    }

            free(word);
            word = NULL;
            numberOfCharacters = 0;
        }
    }

    free(word);
    return name;
}

void printTable(Table *name, unsigned numberOfLines)
{
    putchar('\n');

    for (Table *i = name; i < &name[numberOfLines]; i++)
    {
        printf("%s %u\n", i->name, i->numberOfAparition);
    }
}