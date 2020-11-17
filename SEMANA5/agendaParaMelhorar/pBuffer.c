#include <stdio.h>
#include <stdlib.h>
#include "agenda.h"

int main()
{
    void *pBuffer = createList();
    menu(pBuffer);
    clear(pBuffer);
    return 0;
}

fila *createList()
{
    fila *f = (fila *)malloc(sizeof(fila));

    if (f == NULL)
        exit(1);

    f->first = NULL;
    f->end = NULL;

    return f;
}

int push(void *pBuffer)
{
    nodo *no = (nodo *)malloc(sizeof(nodo));
    if (no == NULL)
        return 0;

    fila *f = (fila *)pBuffer;

    printf("\nDigite o nome: ");
    setbuf(stdin, NULL);
    fgets(no->d.nome, 30, stdin);
    printf("\nDigite a idade: ");
    setbuf(stdin, NULL);
    scanf("%d", &no->d.idade);
    no->prox = NULL;

    if (empty(pBuffer))
    {
        f->first = no;
        no->ant = NULL;
    }
    else
    {
        f->end->prox = no;
        no->ant = f->end->prox;
    }

    f->end = no;

    return 1;
}

int pop(void *pBuffer)
{
    nodo *aux = (nodo *)malloc(sizeof(nodo));
    fila *f = (fila *)pBuffer;

    if (empty(f))
    {
        printf("\nLista vazia!\n");
        free(aux);
        return 0;
    }

    aux = f->first;

    f->d = aux->d;

    f->first = aux->prox;
    aux->prox->ant = NULL;
    aux->prox = NULL;

    if (f->first == NULL)
    {
        f->end = NULL;
        free(aux);
    }
    else
    {
        free(aux);
    }

    return 1;
}

int empty(void *pBuffer)
{
    fila *f = (fila *)pBuffer;

    return (f->first == NULL && f->end == NULL);
}

void clear(void *pBuffer)
{
    fila *f = (fila *)pBuffer;

    if (f->first == NULL)
    {
        free(f);
        return;
    }

    nodo *aux = (nodo *)malloc(sizeof(nodo));

    while (f->first != NULL)
    {
        aux = f->first;
        f->first = aux->prox;
        free(aux);
    }

    if (f != NULL)
        free(f);
}

void sort(void *pBuffer)
{
    fila *f2 = (fila *)pBuffer;
    fila *f = (fila *)malloc(sizeof(fila));
    f = f2;

    for (f->aux = f->first; f->aux != NULL; f->aux = f->aux->prox)
    {
        for (f->aux2 = f->aux->prox; f->aux2 != NULL; f->aux2 = f->aux2->prox)
        {
            if ((f->aux->d.idade > f->aux2->d.idade) && f->i == 1)
            {
                f->d = f->aux->d;
                f->aux->d = f->aux2->d;
                f->aux2->d = f->d;
            }
            if ((f->aux->d.idade < f->aux2->d.idade) && f->i == 2)
            {
                f->d = f->aux->d;
                f->aux->d = f->aux2->d;
                f->aux2->d = f->d;
            }
        }
    }

    free(f);
}

void menu(void *pBuffer)
{
    fila *f = (fila *)pBuffer;

    do
    {

        printf("\n\n----Agenda----");
        printf("\n1-\tAdicionar nome a fila.");
        printf("\n2-\tRemover primeiro nome da fila.");
        printf("\n3-\tImprimir.");
        printf("\n4-\tImprimir ordenado.");
        printf("\n5-\tSair.");
        printf("\nDigite: ");
        scanf("%d", &f->j);

        if (f->j == 1)
            push(pBuffer);

        if (f->j == 2)
            pop(pBuffer);

        if (f->j == 3)
            print(pBuffer);

        if (f->j == 4)
        {
            printf("\n\nFila Ordenada: ");
            printf("\n1-\tOrdem crescente.");
            printf("\n2-\tOrdem decrescente.");
            printf("\nDigite: ");
            scanf("%d", &f->i);

            sort(pBuffer);
            print(pBuffer);
        }

    } while (f->j != 5);
}

void print(void *pBuffer)
{

    fila *f = (fila *)pBuffer;
    nodo *aux = (nodo *)malloc(sizeof(nodo));

    aux = f->first;

    printf("\n\nFila:");

    while (aux != NULL)
    {
        printf("\n|Nome: %s, idade: %d|", aux->d.nome, aux->d.idade);
        aux = aux->prox;
    }
    printf("\n");
    printf("\n");
    printf("\n");

    free(aux);
}