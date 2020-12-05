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

    srand(time(0));

    int op, i, numero;

    printf("\n--------------------------------------------------------------\n");
    printf("\n-------------------------ARVORE AVL---------------------------\n");
    printf("\n--------------------------------------------------------------\n");

    printf("\nDigite o numero de nos: ");
    scanf("%d", &op);

    for(i = 0; i < op; i++){

        numero = rand()%50;
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


    printf("\nDigite quantos numeros para remover: ");
    scanf("%d", &op);

    i = 0;

    while(op != i){

        printf("\nDigite o numero para excluir: ");
        scanf("%d", &numero);

        if(removeNode(root, numero)) printf("\nRemovido!\n");
        else printf("\nNao foi possivel remover\n");

        print(*root);

        if(EhArvoreArvl(root)) printf("\nEh arvore\n");
        else printf("\nNao eh arvore!\n");

        printf("\n");

        i++;
    }

    treeFree(root);



    return 0;
}