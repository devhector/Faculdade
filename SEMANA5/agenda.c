#include <stdio.h>
#include <stdlib.h>
#include "agenda.h"

const int listaVazia = 2;

filas *createList(){

    filas *fila = (filas *)malloc(sizeof(filas));
    if(fila == NULL){
        printf("\nErro de memoria!\n");
        exit(1);
    }

    fila->primeiro = NULL;
    fila->ultimo = NULL;

    return fila;
}

int empty(void *pBuffer){

    filas *fila = (filas *)pBuffer;

    return (fila->primeiro == NULL && fila->ultimo == NULL);
}

int push(void *pBuffer){

    nodos *node = (nodos *)malloc(sizeof(nodos));
    if(node == NULL){
        printf("\nErro de memoria!\n");
        exit(1);
    }

    filas *fila = (filas *)pBuffer;

    printf("\nDigite o nome: ");
    setbuf(stdin, NULL);
    fgets(node->pessoa.nome, 30, stdin);
    printf("\nDigite a idade: ");
    setbuf(stdin, NULL);
    scanf("%d", &node->pessoa.idade);
    
    node->prox = NULL;

    if(empty(pBuffer)){

        fila->primeiro = node;
        node->ant = NULL;

    }else{

        node->ant = fila->ultimo;
        fila->ultimo->prox = node;

    }

    fila->ultimo = node;
    
    return 1;
}

int pop(void *pBuffer){

    if(empty(pBuffer)){
        return listaVazia;
    }

    filas *fila = (filas *)pBuffer;

    nodos *node = fila->primeiro;

    if(node->prox == NULL){
        fila->primeiro = NULL;
        fila->ultimo = NULL;
        free(node);
        return 1;
    }

    fila->primeiro = node->prox;
    node->prox->ant = NULL;
    node->prox = NULL;

    free(node);

    return 1;
    
}

void print(void *pBuffer){

    if(empty(pBuffer)){
        printf("\n\nFila Vazia!\n");
        return;
    }

    filas *fila = (filas *)pBuffer;
    nodos *node = fila->primeiro;

    printf("\n----FILA----\n");

    while (node != NULL){

        printf("\nNome: %s, idade: %d", node->pessoa.nome, node->pessoa.idade);
        node = node->prox;

    }
     
    printf("\n");

}

void menu(void *pBuffer){

    filas *fila = (filas *)pBuffer;

    do{

        printf("\n------MENU------\n");
        printf("\n1-\tAdicionar nome.");
        printf("\n2-\tRetirar nome.");
        printf("\n3-\tImprimir nomes.");
        printf("\n4-\tImprimir nomes ordenados.");
        printf("\n5-\tSair.");
        printf("\nEscolha: ");
        scanf("%d", &fila->opcao);

        if(fila->opcao == 1){

            printf("\n-----ADICIONAR NOME-----\n");
            push(pBuffer);
            printf("\n");

        }

        if(fila->opcao == 2){

            printf("\n------REMOVER NOME------\n");

            if(pop(pBuffer) == listaVazia){

                printf("\nLista Vazia!\n");

            }else{

                printf("\nPrimeiro nome da fila removido.\n");

            }
            
        }

        if(fila->opcao == 3){

            print(pBuffer);

        }

        if(fila->opcao == 4){

            imprimirOrdenado(pBuffer);

        }

        
    } while (fila->opcao != 5);

}

void clear(void *pBuffer){

    filas *fila = (filas *)pBuffer;

    if(empty(pBuffer)){

        free(fila);
        return;

    }

    nodos *node = fila->primeiro;

    while (node != NULL){
        
        fila->primeiro = node->prox;
        free(node);
        node = fila->primeiro;

    }
    
    free(fila);

}

int tamanho(void *pBuffer){

    filas *fila = (filas *)pBuffer;
    nodos *node = fila->primeiro;

    fila->tamanho = 0;

    while (node != NULL){

        fila->tamanho++;
        node = node->prox;
        
    } 

    return fila->tamanho;

}

void imprimirOrdenado(void *pBuffer){

    printf("\n------FILA ORDENADA------");

    if(empty(pBuffer)){
        printf("\n\nFila Vazia!\n");
        return;
    }

    filas *fila = (filas *)pBuffer;
  
    do{

        printf("\n1-\tOrdem crescente.");
        printf("\n2-\tOrdem decrescente.");
        printf("\nEscolha: ");
        scanf("%d", &fila->prioridade);

        if(fila->prioridade != 1 && fila->prioridade != 2){

            printf("\nOpção invalida!\n");

        }
        
    } while (fila->prioridade != 1 && fila->prioridade != 2);  

    fila->tamanho = tamanho(pBuffer);

    fila->ordem = (int *)malloc(sizeof(int) * fila->tamanho);

    nodos *node = fila->primeiro;

    fila->i = 0;

    while (node != NULL){

        fila->ordem[fila->i] = node->pessoa.idade;
        node = node->prox;
        fila->i++;

    } 

    for(fila->i = 0; fila->i < fila->tamanho; fila->i++){

        for(fila->j = 0; fila->j < fila->tamanho; fila->j++){

            if((fila->ordem[fila->i] < fila->ordem[fila->j]) && fila->prioridade == 1){

                fila->aux = fila->ordem[fila->i];
                fila->ordem[fila->i] = fila->ordem[fila->j];
                fila->ordem[fila->j] = fila->aux;

            }

            if((fila->ordem[fila->i] > fila->ordem[fila->j]) && fila->prioridade == 2){

                fila->aux = fila->ordem[fila->i];
                fila->ordem[fila->i] = fila->ordem[fila->j];
                fila->ordem[fila->j] = fila->aux;

            }

        }
    }

    printf("\n");

    for(fila->i = 0; fila->i < fila->tamanho; fila->i++){

        node = fila->primeiro;

        while (node != NULL){
            
            if(fila->ordem[fila->i] == node->pessoa.idade){

                printf("\nNome: %s, idade: %d", node->pessoa.nome, node->pessoa.idade);
                break;
        
            }

            node = node->prox;

        }
        
    }

    printf("\n");

    free(fila->ordem);

}