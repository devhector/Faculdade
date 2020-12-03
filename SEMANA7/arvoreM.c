#include <stdio.h>
#include <stdlib.h>

typedef struct node{

    int data;
    struct node *nodeLeft;
    struct node *nodeRight;

}treeNode;


treeNode **clear(treeNode **node);
int insert(treeNode **node, int data);
int height(treeNode *node);
int balanceFactor(treeNode *node);
int leftBalance(treeNode **node);
int rightBalance(treeNode **node);
void SimpleRotationLeft(treeNode **node);
void SimpleRotationRight(treeNode **node);
int balance(treeNode **node);
//void printBf(treeNode *node);


treeNode **clear(treeNode **node){

    if(node != NULL){

        clear(&(*node)->nodeRight);
        clear(&(*node)->nodeLeft);
        free(*node);
        
    }

    return NULL;
}

int insert(treeNode **node, int data){

    if (node == NULL){

        (*node) = (treeNode *)malloc(sizeof(treeNode));
        if((*node) == NULL){

            printf("\nErro de memoria!\n");
            exit(1);

        }

        (*node)->data = data;
        (*node)->nodeRight = NULL;
        (*node)->nodeLeft = NULL;

        return 1;

    } else if((*node)->data > data){

        if(insert(&(*node)->nodeLeft, data)){

            return !balance(node);

        } else{
            
            return 0;

        }
        

    } else if((*node)->data > data){

        if(insert(&(*node)->nodeRight, data)){

            return !balance(node);

        } else{

            return 0;

        }

    } else {

        return 0;

    }


}

int height(treeNode *node){

    if(node == NULL)
        return 0;

    int heightLeft = height(node->nodeLeft);
    int heightRight = height(node->nodeRight);
    
    return (heightLeft > heightRight) ? (heightLeft + 1) : (heightRight + 1);

}

int balanceFactor(treeNode *node){

    if (node == NULL){

        return 0;

    }

    return height(node->nodeLeft) - height(node->nodeRight);

}

void SimpleRotationLeft(treeNode **node){

    treeNode *aux;

    aux = (*node)->nodeRight;
    (*node)->nodeRight = aux->nodeLeft;
    aux->nodeLeft = (*node);
    (*node) = aux;

}

void SimpleRotationRight(treeNode **node){

    treeNode *aux;

    aux = (*node)->nodeLeft;
    (*node)->nodeLeft = aux->nodeRight;
    aux->nodeRight = (*node);
    (*node) = aux;

}

int leftBalance(treeNode **node){

    int leftBalanceFactor = balanceFactor((*node)->nodeLeft);

    if(leftBalanceFactor > 0){

        SimpleRotationRight(node);
        return 1;

    } else if(leftBalanceFactor < 0){

        SimpleRotationLeft(&(*node)->nodeLeft);
        SimpleRotationRight(&(*node));
        return 1;

    }

    return 0;

}

int rightBalance(treeNode **node){

    int rightBalanceFactor = balanceFactor((*node)->nodeRight);

    if(rightBalanceFactor < 0){

        SimpleRotationLeft(node);
        return 1;

    } else if(rightBalanceFactor > 0){

        SimpleRotationRight(&(*node)->nodeRight);
        SimpleRotationLeft(&(*node));
        return 1;

    }

    return 0;

}

int balance(treeNode **node){

    int BalanceFactor = balanceFactor(*node);

    if(BalanceFactor > 1){

        return leftBalance(node);

    } else if( BalanceFactor < -1){

        return rightBalance(node);

    } 

    return 0;

}

int main(){

    treeNode **root = NULL;

    insert(root, 9);
    insert(root, 7);
    insert(root, 8);
    insert(root, 4);
    insert(root, 11);
    insert(root, 10);
    insert(root, 12);
    insert(root, 5);
    insert(root, 3);
    insert(root, 2);
    insert(root, 1);


    printf("\nAltura: %d\n", height(*root));

    //printBf(root);

    clear(root);

    return 0;
}