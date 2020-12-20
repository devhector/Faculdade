#include <stdio.h>
#include <stdlib.h>

typedef struct Data{

    int number;

}data;

typedef struct Queue{

    data number;
    struct Queue *next;
    struct Queue *last;

}queue;

queue **createQueue();
int isEmpety(queue **principal);
int dequeue(queue **principal, data *value);
void enqueue(queue **principal, data value);
void printQueue(queue **principal);
void freeQueue(queue **principal);
void freeElement(queue *node);


int main(){

    int op;
    data mainData;
    queue **principal = createQueue();


    do{

        printf("\n-----FILA-----\n");
        printf("\n1 - Adicionar elemento na fila.");
        printf("\n2 - Remover elemento do inicio.");
        printf("\n3 - Imprimir a fila.");
        printf("\n0 - Sair");
        printf("\nDigite: ");
        scanf("%d", &op);


        if(op == 1){

            printf("\n\nInserir elemento na fila.");
            printf("\nDigite o numero: ");
            scanf("%d", &mainData.number);

            enqueue(principal, mainData);

        }else if(op == 2){

            if(dequeue(principal, &mainData)){

                printf("\nElemento %d retirado.\n", mainData.number);    

            }else{

                printf("\nA fila esta vazia.\n");

            }

            

        }else if(op == 3){

            printQueue(principal);

        }
        
    } while (op != 0);

    freeQueue(principal);

    return 0;
}

int isEmpety(queue **principal){

    if(principal == NULL){

        return 1;

    }else if (*principal == NULL){

        return 1;

    }

    return 0;

}

queue **createQueue(){

    queue **principal = (queue **)malloc(sizeof(queue *));
    if(principal == NULL){

        printf("\nERRO! Memoria insuficiente!\n");
        exit(1);

    }

    *principal = NULL;

    return principal;

}

void enqueue(queue **principal, data value){

    queue *node = (queue *)malloc(sizeof(queue));
    if(node == NULL){

        printf("\nERRO! Memoria insuficiente!\n");
        exit(1);

    }

    if(isEmpety(principal)){

        *principal = node;
        (*principal)->last = node;
        node->next = NULL;
        node->number = value;

    }else{

        queue *aux = *principal;

        aux->last->next = node;
        aux->last = node;
        node->number = value;
        node->next = NULL;

    }

}

int dequeue(queue **principal, data *value){

    if(isEmpety(principal)){

        return 0;

    }else{

        queue *aux = *principal;

        *principal = aux->next;

        value->number = aux->number.number;

        free(aux);

        return 1;

    }

    return 0;

}

void printQueue(queue **principal){

    queue *aux = *principal;

    printf("\n-------- Fila --------\n");

    if(aux == NULL){

        printf("fila vazia!");

    }

    while (aux != NULL){
        
        printf("%d ", aux->number.number);
        aux = aux->next;

    }
    
    printf("\n----------------------\n");

}

void freeElement(queue *node){

    if(node == NULL) return;

    freeElement(node->next);

    free(node);
    
}

void freeQueue(queue **principal){

    freeElement(*principal);
    free(principal);

}