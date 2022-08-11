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

    int op, i, num, op2, num2;

    printf("\n##############################################################\n");
    printf("\n#------------------------ARVORE AVL--------------------------#\n");
    printf("\n##############################################################\n");

    printf("\nDigite o numero de nos: ");
    scanf("%d", &op);

    printf("\nDeseja limitar o intervalo de 0 a um numero especifico?\n");
    printf("1 - Sim | 2 - Nao\n\n");
    
    do
    {
        printf("Digite: ");
        scanf("%d", &op2);

        if(op2 != 1 && op2 != 2) printf("\nOpcao invalida\n");
        
    } while (op2 != 1 && op2 != 2);
    
    if(op2 == 1){
        
        do{
            
            printf("\nDigite o numero limite: ");
            scanf("%d", &num2);

            if(num2 < 0)printf("\nNumero invalido\n");

        }while (num2 < 0);
        

    }

    printf("\n");

    for(i = 0; i < op; i++){

        if(op2 == 1){

            num = rand() % num2;

        }else{

            num = rand();

        }

        insert(root, num);
        printf(" %d ", num);
        if((i + 1) % 3 == 0) printf("\n");

    }

    printf("\n");

    printf("\nAltura: %d\n", height(*root));


    if(EhArvoreArvl(root)) printf("\nEh arvore\n");
    else printf("\nNao eh arvore!\n");

    printf("\n");

    i = 0;
    printTreeTwoD(*root, i);

    printf("\n");
    
    treeFree(root);

    return 0;
}