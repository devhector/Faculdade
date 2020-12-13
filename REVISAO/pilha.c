#include <stdio.h>
#include <stdlib.h>

typedef struct stack{

    int number;
    struct stack *next;

}Stack;

int isEmpty(Stack **varStack);
int pop(Stack **varStack, int *data);
void push(Stack **varStack, int data);
void showTop(Stack **varStack);
void stackFree(Stack **varStack);
void elementFree(Stack *elementStack);
Stack **createStack();

int main(){

    int op, data;
    Stack **varStack = createStack();
    
    do{

        printf("\n-----PILHA-----\n");
        printf("\n1 - Adicionar elemento na pilha.");
        printf("\n2 - Remover elemento do topo.");
        printf("\n3 - Imprimir elemento do topo.");
        printf("\n4 - Imprimir pilha.");
        printf("\n0 - Sair");
        printf("\nDigite: ");
        scanf("%d", &op);


        if(op == 1){

            printf("\n\nInserir elemento na pilha.");
            printf("\nDigite o numero: ");
            scanf("%d", &data);

            push(varStack, data);

        }else if(op == 2){

            if(pop(varStack, &data)){

                printf("\nElemento %d retirado.\n", data);    

            }else{

                printf("\nA pilha esta vazia.\n");

            }

            

        }else if(op == 3){

            showTop(varStack);

        }else if(op == 4){

            printf("\nNão implementado\n");

        }
        
    } while (op != 0);
    
    stackFree(varStack);

    return 0;
}

int isEmpty(Stack **varStack){

    if(varStack == NULL){

        return 1;

    }

    if(*varStack == NULL){

        return 1;

    }

    return 0;

}

void push(Stack **varStack, int data){

    Stack *elementStack = (Stack *)malloc(sizeof(Stack));
    if(elementStack == NULL){

        printf("\nERRO! Falta de memoria\n");
        exit(1);

    }

    if(isEmpty(varStack)){

        *varStack = elementStack;
        elementStack->number = data;
        elementStack->next = NULL;


    }else{

        elementStack->next = *varStack;
        elementStack->number = data;
        *varStack = elementStack;

    }

}

int pop(Stack **varStack, int *data){

    Stack *aux;

    if(!isEmpty(varStack)){

        aux = *varStack;
        *varStack = aux->next;
        *data = aux->number;

        free(aux);

        return 1;

    }

    return 0;

}

void showTop(Stack **varStack){

    printf("\nTopo: %d\n", (*varStack)->number);

}

Stack **createStack(){
    
    Stack **varStack = (Stack **)malloc(sizeof(Stack *));
    if(varStack == NULL){

        printf("\nERRO! Memoria insuficiente.\n");
        exit(1);

    }

    *varStack = NULL;

    return varStack;
}

void stackFree(Stack **varStack){

    if(varStack == NULL) return;

    elementFree(*varStack);

    free(varStack);

}

void elementFree(Stack *elementStack){

    if(elementStack == NULL) return;

    elementFree(elementStack->next);

    free(elementStack);

}