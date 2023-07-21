#include <ctype.h>
#include <stdio.h>

int main()
{
    char s[100];
    int i;
    printf("textul: ");
    fgets(s, 100, stdin); // se citesc maxim 99 de caractere+\0; dacă sunt mai puține, la sfarsit se va depune și \n
    for (i = 0; s[i]; i++)
    { // se itereaza atata timp cat inca nu s-a ajuns la terminatorul de sir
        s[i] = toupper(s[i]);
    }
    printf("text final: %s", s);
    return 0;
}
