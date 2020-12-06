#include <stdio.h>
#include <stdlib.h>

typedef struct node{

    int data;
    struct node *nodeLeft;
    struct node *nodeRight;

}treeNode;

treeNode **createAvlTree();
treeNode *smaller(treeNode *node);
int height(treeNode *root);
int insert(treeNode **root, int data);
int balanceFactor(treeNode *root);
int leftBalance(treeNode **root);
int rightBalance(treeNode **root);
int removeNode(treeNode **root, int data);
int balance(treeNode **root);
void treeFree(treeNode **root);
void SimpleRotationLeft(treeNode **root);
void SimpleRotationRight(treeNode **root);
void print(treeNode *node);
void nodeFree(treeNode *node);
int findElement(treeNode **root, int data);