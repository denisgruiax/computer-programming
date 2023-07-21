#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *foo(char *p, char *word, unsigned int wordLenght);

int main()
{
    char *storeText = NULL, string[30];

    for (unsigned int count;; count++)
    {
        printf("word %u: ", count);
        fgets(string, 30, stdin);

        string[strlen(string) - 1] = '\0';

        if (!strlen(string))
            break;

        storeText = foo(storeText, string, strlen(string));
    }

    puts(storeText);
    free(storeText);
    return 0;
}

char *foo(char *text, char *word, unsigned int wordLenght)
{
    static int firstWord = 0;
    static unsigned int textLenght = 0;
    textLenght += wordLenght + 1;

    if (!(text = (char *)realloc(text, textLenght * sizeof(char))))
    {
        free(text);
        puts("error...");
        exit(EXIT_FAILURE);
    }

    //printf("%c %c\n", word[0], word[1]);
    //printf("%c %c\n\n", text[strlen(text) - 2], text[strlen(text) - 1]);
    
    if (!firstWord)
    {
        strcpy(text, word);
        firstWord = 1;
        return text;
    }

    if ((tolower(word[0]) == tolower(text[strlen(text) - 2])))
    {
        if ((tolower(word[1]) == tolower(text[strlen(text) - 1])))
        {
            strcat(text, "-");
            strcat(text, word);
        }
    }

    return text;
}