#include <stdio.h>
#include <stdlib.h>

typedef struct node{

    int data;
    struct node *nodeLeft;
    struct node *nodeRight;

}treeNode;

treeNode **createAvlTree();

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