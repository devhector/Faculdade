#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct {
    char nome[60];
}pessoa;

typedef struct{
    int qtd, 
        resposta,
        i;
}variavel;



void readStr(char *name);
void *addName(void *pBuffer, variavel *var, pessoa *p);
void *rmName(void *pBuffer);
void printName(void *pBuffer);


int main(){

    int t = 3;
    void *pBuffer = malloc(sizeof(variavel));
    variavel *var;
    pessoa *p = (pessoa *)malloc(sizeof(pessoa));

    var = pBuffer;

    var->qtd = 0;
    pBuffer = var;
    pBuffer = sizeof(var) + p;

    while(t--)
        pBuffer = addName(pBuffer, var, p);


    return 0;
}

void readStr(char *name)
{

    char c;
    c = getchar();
    int i = 0;

    while (c != '\n')
    {
        name[i] = c;
        c = getchar();
        i++;
        if(i > 58) break;
    }
    name[i] = '\0';

}

void *addName(void *pBuffer, variavel *var, pessoa *p){

	if((pBuffer=realloc(pBuffer,sizeof(variavel)+sizeof(pessoa)+(var->qtd * sizeof(pessoa))))==NULL){
        printf("Nao foi possivel alocar memoria");
        exit(1);
	}
	var = pBuffer;
	p = pBuffer + sizeof(variavel) + (var->qtd * sizeof(pessoa));

	printf("Escreva um nome:\n");
    readStr(p->nome);

	var->qtd++;

    return pBuffer;

}

void printName(void *pBuffer){
    variavel *var;
    pessoa *p;

    var = pBuffer;
    p = (pessoa *) pBuffer + sizeof(variavel);

    for(var->i = 0; var->i < var->qtd; var->i++){
        printf("%s\n", p->nome);
        p++;
    }

    // free(var);
    // free(p);
}