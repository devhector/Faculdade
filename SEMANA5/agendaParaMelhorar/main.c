#include <stdio.h>
#include<stdlib.h>
#include "agenda.h"

int main()
{
    void *pBuffer = createList();
    
    menu(pBuffer);
    clear(pBuffer);
    return 0;
}

fila *createList(){
    fila *f = (fila *)malloc(sizeof(fila));
    if(f == NULL) exit(1);

    f->first = NULL;
    f->end = NULL;

    return f;
}

int push(void *pBuffer){    
    nodo *no = (nodo *)malloc(sizeof(nodo));
    if(no == NULL) return 0;
   
    fila *f = (fila *)pBuffer;

    printf("\nDigite o nome: ");
    setbuf(stdin, NULL);
    readStr(no->d.nome);
    printf("\nDigite a idade: ");
    setbuf(stdin, NULL);
    scanf("%d", &no->d.idade);
    no->prox = NULL;

    if(empty(pBuffer)){
        f->first = no;
    }else{
        f->end->prox = no;
    }

    f->end = no;

    //pBuffer = f;

    return 1;
}

int pop(void *pBuffer){
    nodo *aux = (nodo *)malloc(sizeof(nodo));
    fila *f =(fila *)pBuffer;

    if(empty(f)){
        printf("\nLista vazia!\n");
        free(aux);
        return 0;
    }
        

    aux = f->first;

    f->d = aux->d;

    f->first = aux->prox;
    aux->prox = NULL;

    if(f->first == NULL){
        f->end = NULL;
        free(aux);
    }

   // pBuffer = f;

    return 1;
}

int empty(void *pBuffer){
    fila *f = (fila *)pBuffer;

    return (f->first == NULL && f->end == NULL);
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
        if(i > 28) break;
    }
    name[i] = '\0';

}

void clear(void *pBuffer){
    fila *f = (fila *)pBuffer;

    if(f->first == NULL) return;

    nodo *aux = (nodo *)malloc(sizeof(nodo));
    nodo *aux1 = (nodo *)malloc(sizeof(nodo));


    aux = f->first;

    while (aux != NULL)
    {
        aux1 = aux->prox;
        
        if(aux != NULL)
            free(aux);
        
        aux = aux1->prox;
    }
    
    if(aux1 != NULL)
        free(aux1);

}

void print(void *pBuffer){
    fila *f = (fila *)pBuffer;
    nodo *aux = (nodo *)malloc(sizeof(nodo));

    aux = f->first;

    printf("\n\nFila:");

    while (aux != NULL){
        printf("\nNome: %s | idade: %d", aux->d.nome, aux->d.idade);
        aux = aux->prox;
    }
    printf("\n");
    printf("\n");
    printf("\n");

    setbuf(stdin, NULL);
    printf("Aperte enter para continuar...");
    getchar();
}

void clearScreen(){
#ifdef OS_Win
system("cls");
#else
system("clear");
#endif
}

void menu(void *pBuffer){
    
    fila *f = (fila *)pBuffer;

    do
    {
        clearScreen();
        printf("\nMenu:");
        printf("\n1\t-\tAdicionar nome.");
        printf("\n2\t-\tTirar primeiro nome.");
        printf("\n3\t-\tImprimir.");
        printf("\n4\t-\tSair.");
        printf("\nDigite: ");
        scanf("%d",&f->i);

        if(f->i == 1)
            push(pBuffer);

        if(f->i == 2)
            pop(pBuffer);

        if(f->i == 3)
            print(pBuffer);

    } while (f->i != 4);
}