#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int readStr(char *str);

int main(){

    char linha[80], aux[80];
    int tm = 0, i = 0, j = 0;
    linha[0] = '\0';
    aux[0] = '\0';

    while(tm < 80){
        printf("\nDigite o nome %d: ", i + 1);
        tm += readStr(aux);
        strcat(linha, aux);
        i++;
    }

    for(i = 0; i < 80; i++){
        if(linha[i] == ','){
            printf("\n%d - ", j + 1);
            j++;
            i++;
        }
        printf("%c", linha[i]);
    }

    printf("\n");

    return 0;
}

int readStr(char *str)
{

    char c;
    c = ',';
    int i = 0;

    while (c != '\n')
    {
        str[i] = c;
        c = getchar();
        i++;
        if(i > 78){
            str[i] = '\0';
             return 0;
        }
    }
    str[i] = '\0';

    return i;
}