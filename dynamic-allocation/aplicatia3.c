#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int allocPointer();
char *foo();

int main()
{
    char *store = NULL;
    store = foo();
    puts(store);

    free(store);
    
    return 0;
}

int allocPointer()
{
    char *pointer = NULL, ch;
    unsigned int numberOfOctets = 0;
    for (;;)
    {
        numberOfOctets++;

        pointer = (char *)realloc(pointer, numberOfOctets);
        if (!pointer)
        {
            free(pointer);
            printf("eroare...\n");
            exit(EXIT_FAILURE);
        }
        ch = getchar();
        if (ch == '\n')
            break;

        pointer[numberOfOctets - 1] = ch;
    }

    return pointer;
}
char *foo()
{
    char *pointer1 = NULL, *pointer2 = NULL, *store = NULL;

    pointer1 = allocPointer();
    pointer2 = allocPointer();

    unsigned int sizeOfStore = strlen(pointer1) + strlen(pointer2) + 1;

    store = (char *)realloc(store, sizeOfStore);
    if (!store)
    {
        free(store);
        printf("eroare...\n");
        exit(EXIT_FAILURE);
    }
    
    strcpy(store, pointer1);
    strcat(store, " ");
    strcat(store, pointer2);

    return store;
}