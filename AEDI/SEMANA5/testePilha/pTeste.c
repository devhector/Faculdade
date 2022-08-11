#include <stdio.h>
#include <stdlib.h>

typedef struct dd{
    int id;
}dado;

typedef struct n{
    dado d;
    struct n *prox;
}nodo;

typedef struct{
    int size;
    nodo *topo;
}list;

list *createList();
void push(list *lista, dado d);
void print(list *lista);


int main(){

    list *lista;
    dado d;
    lista = createList();
    
    d.id = 3;
    push(lista, d);

    d.id = 5;
    push(lista, d);

    d.id = 9;
    push(lista, d);

    print(lista);

    return 0;
}

list *createList(){
    list *lista = (list *)malloc(sizeof(list));

    lista->size = 0;
    lista->topo = NULL;

    return lista;
}

void push(list *lista, dado d){
    nodo *no = (nodo *)malloc(sizeof(nodo));

    no->d = d;
    no->prox = lista->topo;
    lista->topo = no;
    lista->size++;
}

void print(list *lista){
    nodo *no = lista->topo;

    if(no == NULL) printf("\nLista vazia!\n");

    while (no != NULL)
    {
        printf("%d\n", no->d.id);
        no = no->prox;
    }

    printf("\n");   
}