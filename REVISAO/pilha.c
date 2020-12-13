#include <stdio.h>
#include <stdlib.h>

typedef struct stack{

    int number;
    struct stack *next;

}Stack;

int isEmpty(Stack **varStack);

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