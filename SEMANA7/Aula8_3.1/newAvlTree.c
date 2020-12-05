#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "avltree.h"


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

*/

    srand(time(0));

    int op, i, numero;

    printf("\n--------------------------------------------------------------\n");
    printf("\n-------------------------ARVORE AVL---------------------------\n");
    printf("\n--------------------------------------------------------------\n");

    printf("\nDigite o numero de nos: ");
    scanf("%d", &op);

    for(i = 0; i < op; i++){

        numero = rand();
        insert(root, numero);
        printf(" %d ", numero);
        if(i != op - 1) printf("-");
        if((i + 1) % 3 == 0) printf("\n");

    }



    printf("\nAltura: %d\n", height(*root));

    printf("\n");

    if(EhArvoreArvl(root)) printf("\nEh arvore\n");
    else printf("\nNao eh arvore!\n");

    print(*root);

    printf("\n");
    

    treeFree(root);

    return 0;
}