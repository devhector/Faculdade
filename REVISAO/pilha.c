#include <stdio.h>
#include <stdlib.h>

typedef struct stack{

    int number;
    struct stack *next;

}Stack;

int isEmpty(Stack **varStack);
void push(Stack **varStack, int data);

int main(){



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

    if(isEmpty(varStack)){

        varStack = &elementStack;
        elementStack->number = data;
        elementStack->next = NULL;


    }else{

        elementStack->next = *varStack;
        elementStack->number = data;
        varStack = &elementStack;

    }
    
}