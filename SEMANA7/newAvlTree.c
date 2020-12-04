#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct node{

    int data;
    struct node *nodeLeft;
    struct node *nodeRight;

}treeNode;

treeNode **createAvlTree();
void nodeFree(treeNode *node);
void treeFree(treeNode **root);
int height(treeNode *root);
int insert(treeNode **root, int data);
int balanceFactor(treeNode *root);
void SimpleRotationLeft(treeNode **root);
void SimpleRotationRight(treeNode **root);
int leftBalance(treeNode **root);
int rightBalance(treeNode **root);
int balance(treeNode **root);



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

int EhArvoreArvl(treeNode **root)
{
    treeNode *pRaiz = *root;
    int fb;
    if (pRaiz == NULL)
        return 1;
    if (!EhArvoreArvl(&pRaiz->nodeLeft))
        return 0;
    if (!EhArvoreArvl(&pRaiz->nodeRight))
        return 0;
    fb = balanceFactor(pRaiz);
    if ( ( fb > 1 ) || ( fb < -1) )
        return 0;
    else
        return 1;
}

int main(){

    treeNode **root = createAvlTree();


/*
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
    insert(root, 13);
    insert(root, 15);
    insert(root, 17);
    insert(root, 14);
    insert(root, 12);
*/

    srand(time(0));

    int op, i;

    scanf("%d", &op);

    for(i = 0; i < op; i++)
        insert(root, rand());

    printf("\nAltura: %d\n", height(*root));

    printf("\n");

    printf("\n%d\n", EhArvoreArvl(root));


    treeFree(root);

    return 0;
}