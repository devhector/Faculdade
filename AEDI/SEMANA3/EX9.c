#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *Teste(char *s1, const char *s2);

int main()
{

    return 0;
}

char *Teste(char *s1, const char *s2)
{
    char *aux = s1;
    while (*s1)
        s1++;
    for (; (*s1 = *s2) != '\0' ; s1++, s2++);
    return aux;
}

