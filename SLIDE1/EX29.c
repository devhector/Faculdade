#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int readStr(char *c);
char *addName(char *str, int *count);
void print(char *str);
char *rmName(char *str, int *count);

int main()
{
    char *string = (char *) malloc(sizeof(char));

    int count = 0, i;

    while (1)
    {
        printf("\n");
        printf("-------------------------\n");
        printf("1 - Adicionar nome\n");
        printf("2 - Remover nome\n");
        printf("3 - Imprimir nomes\n");
        printf("4 - Sair\n");
        printf("Digite: ");
        scanf("%d", &i);
        setbuf(stdin, NULL);

        if(i == 1) string = addName(string, &count);
        if(i == 2) string = rmName(string, &count);
        if(i == 3) print(string);
        if(i == 4) break;


    }
    

    string = rmName(string, &count);



    free(string);
    return 0;
}

int readStr(char *name)
{

    char c;
    c = ',';
    int i = 0;

    while (c != '\n')
    {
        name[i] = c;
        c = getchar();
        i++;
        if(i > 58) return 0;
    }
    name[i] = '\0';

    return i;
}

char *addName(char *str, int *count){

    char tmp[60];
    int length;

    printf("\nDigite o nome a ser adicionado: ");
    length = readStr(tmp);
    *count += length;

    str = realloc(str, (*count + 1) * sizeof(char));
    if(!str){
        printf("ERROR MEMÓRIA INSUFICIENTE! \n");
        return 0;
    }

    strcat(str, tmp);

    return str;
}

char *rmName(char *str, int *count){
    int i, j = 0, aux = 0, pos;

    printf("\nDigite o numero do nome que deseja retirar: ");
    scanf("%d", &i);

    while(str[j] != '\0'){
        if(str[j] == ','){
            if(aux == (i - 1)){
                break;
            }
        else aux++;
        }
        j++;
    }
    pos = j;
    aux = 0;
    j++;

    while(str[j] != ','){
        aux++;
        j++;
    }

    while(str[j] != '\0'){
        str[pos] = str[j];
        pos++;
        j++;
    }

    str[pos] = '\0';

    *count -= aux;

    str = realloc(str, (*count + 1) * sizeof(char));
    if(!str){
        printf("ERROR MEMÓRIA INSUFICIENTE! \n");
        return 0;
    }    


    return str;
}

void print(char *str){
    int i = 0, j = 1;

    while (str[i] != '\0')
    {
        if(str[i] == ','){
            printf("\n");
            printf("%d - ", j);
            j++;
        }else
        {
            printf("%c", str[i]);
        }
        i++;
    }
    
    printf("\n");
}