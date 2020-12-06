#include <stdio.h>
#include <stdlib.h>
#include "avltree.h"


treeNode **createAvlTree(){

    treeNode **root = (treeNode **)malloc(sizeof(treeNode *));
    if(root == NULL){

        printf("\nErro, falta de memoria!");
        exit(1);

    }

    *root = NULL;

    return root;

}

void nodeFree(treeNode *node){

    if(node == NULL) return;

    nodeFree(node->nodeLeft);
    nodeFree(node->nodeRight);
    free(node);

}

void treeFree(treeNode **root){

    if(root == NULL) return;

    nodeFree(*root);
    free(root);


}

int height(treeNode *root){

    if(root == NULL) return 0;


    int heightLeft = height(root->nodeLeft);
    int heightRight = height(root->nodeRight);
    
    return (heightLeft > heightRight) ? (heightLeft + 1) : (heightRight + 1);

}


int insert(treeNode **root, int data){

    if(*root == NULL){

        treeNode *node = (treeNode *)malloc(sizeof(treeNode));
        if(node == NULL){

            printf("\nERRO, memoria insuficiente.\n");
            exit(1);

        }

        node->data = data;
        node->nodeLeft = NULL;
        node->nodeRight = NULL;

        *root = node;

        return 1;

    }else if((*root)->data > data){

        if(insert(&(*root)->nodeLeft, data)){

            balance(root);
            return 1;

        }else{

            return 0;

        }

    }else if((*root)->data < data){

        if(insert(&(*root)->nodeRight, data)){

            balance(root);
            return 1;

        }else{

            return 0;

        }

    }else{

        return 0;

    }
}

int balanceFactor(treeNode *root){

    if (root == NULL){

        return 0;

    }

    return height(root->nodeLeft) - height(root->nodeRight);

}

void SimpleRotationLeft(treeNode **root){

    treeNode *aux;

    aux = (*root)->nodeRight;
    (*root)->nodeRight = aux->nodeLeft;
    aux->nodeLeft = (*root);
    (*root) = aux;

}

void SimpleRotationRight(treeNode **root){

    treeNode *aux;

    aux = (*root)->nodeLeft;
    (*root)->nodeLeft = aux->nodeRight;
    aux->nodeRight = (*root);
    (*root) = aux;

}

int leftBalance(treeNode **root){

    int leftBalanceFactor = balanceFactor((*root)->nodeLeft);

    if(leftBalanceFactor > 0){

        SimpleRotationRight(root);
        return 1;

    } else if(leftBalanceFactor < 0){

        SimpleRotationLeft(&(*root)->nodeLeft);
        SimpleRotationRight(&(*root));
        return 1;

    }

    return 0;

}

int rightBalance(treeNode **root){

    int rightBalanceFactor = balanceFactor((*root)->nodeRight);

    if(rightBalanceFactor < 0){

        SimpleRotationLeft(root);
        return 1;

    } else if(rightBalanceFactor > 0){

        SimpleRotationRight(&(*root)->nodeRight);
        SimpleRotationLeft(&(*root));
        return 1;

    }

    return 0;

}

int balance(treeNode **root){

    int BalanceFactor = balanceFactor(*root);

    if(BalanceFactor > 1){

        return leftBalance(root);

    } else if( BalanceFactor < -1){

        return rightBalance(root);

    } 

    return 0;

}


void print(treeNode *node){

    if(node == NULL) return;

        print(node->nodeLeft);

        printf(" %d ", node->data);

        print(node->nodeRight);
 
}

treeNode *smaller(treeNode *node){
    treeNode *aux = node;
    treeNode *oneAux = node->nodeLeft;

    while (oneAux != NULL)
    {
        
        aux = oneAux;
        oneAux = oneAux->nodeLeft;

    }
    
    return aux;

}

int removeNode(treeNode **root, int data){

    if(*root == NULL){

        return 0;

    }

    if(data < (*root)->data){

        if(removeNode(&(*root)->nodeLeft, data)){

            balance(root);
            return 1;

        } else {

            return 0;

        }

    } else if (data > (*root)->data){

        if(removeNode(&(*root)->nodeRight, data)){

            balance(root);
            return 1;

        } else {

            return 0;

        }

    }

    if(data == (*root)->data){


        if((*root)->nodeLeft == NULL || (*root)->nodeRight == NULL){

            treeNode *aux = *root;

            if((*root)->nodeRight != NULL){

                (*root) = (*root)->nodeRight;

            } else{

                (*root) = (*root)->nodeLeft;

            }

            free(aux);

            return 1;

        } else {

            treeNode *aux = smaller((*root)->nodeRight);

            (*root)->data = aux->data;

            removeNode(&(*root)->nodeRight, aux->data);

            balance(root);

        }

        return 1;

    }

    return 1;

}

int findElement(treeNode **root, int data){
    
    treeNode *node = *root;

    if(node == NULL){

        return 0;

    }

    if(node->data == data){
        
        return 1;

    }else if(node->data < data){

        return findElement(&node->nodeRight, data);

    } else if(node->data > data) {

        return findElement(&node->nodeLeft, data); 

    }

    return 0;

}