#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "avltree.h"

void menu(treeNode **root, int option);
int EhArvoreArvl(treeNode **root);


int main(){

    treeNode **root = createAvlTree();

    srand(time(0));

    int option;

    printf("\n##############################################################\n");
    printf("\n#------------------------ARVORE AVL--------------------------#\n");
    printf("\n##############################################################\n");

    do
    {
        printf("\n");
        printf("\n1 - Adicionar elemento.");
        printf("\n2 - Remover elemento.");
        printf("\n3 - Encontrar elemento.");
        printf("\n4 - Imprimir elementos.");
        printf("\n0 - Sair.");
        printf("\nDigite: ");

        scanf("%d", &option);

        if(option < 0 && option > 4){

            printf("\nOpcao invalida");
            
        }else if(option != 0) {

            menu(root, option);

        }


    } while (option != 0);
    


/*
    printf("\nDigite o numero de nos: ");
    scanf("%d", &op);

    for(i = 0; i < op; i++){

        numero = rand();
        insert(root, numero);
        printf(" %d ", numero);
        if((i + 1) % 3 == 0) printf("\n");

    }



    printf("\nAltura: %d\n", height(*root));

    printf("\n");

    if(EhArvoreArvl(root)) printf("\nEh arvore\n");
    else printf("\nNao eh arvore!\n");

    print(*root);


    printf("\nDigite quantos numeros para remover: ");
    do{

        scanf("%d", &op2);

    }while(op2 < 0 && op < op2);

    i = 0;

    while(op2 != i){

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
*/

    treeFree(root);

    return 0;
}

void menu(treeNode **root, int option){

    int op, num, i, number, aux;

    srand(time(0));

    if(option == 1){

        printf("\n1 - Inserir apenas um valor.");
        printf("\n2 - Inserir numeros aleatorios.");
        printf("\nDigite: ");

        do{
            
            scanf("%d", &op);

            if(op != 1 && op != 2) printf ("\nopcao invalida\n");

        } while (op != 1 && op != 2);

        if(op == 1){

            printf("\nDigite o numero a ser inserido: ");
            scanf("%d", &num);
            insert(root, num);

        } else {
            
            printf("\nDigite o numero de nos: ");
            scanf("%d", &num);


            printf("\nDeseja limitar o intervalo?\n1 - Sim. | 2 - Nao.\nDigite: ");

            do{
                
                scanf("%d", &op);

                if(op != 1 && op != 2) printf ("\nOpcao invalida\n");

            } while (op != 1 && op != 2);

            if(op == 1){

                printf("\nDigite o numero limite: ");
                scanf("%d", &number);

                for(i = 0; i < num; i++){

                    insert(root, rand() % number);

                }

                return;

            }else {

                for(i = 0; i < num; i++){

                    insert(root, rand());

                }

                return;

            }

        }
        

    }else if (option == 2){

        printf("\nDigite o numero a ser excluido: ");
        scanf("%d", &num);

        if(removeNode(root, num)){

            printf("\nNumero removido!");

        }else{

            printf("\nNumero nao encontrado.");

        }

        return;

    }else if(option == 3){

        printf("\nDigite o numero a ser procurado: ");
        scanf("%d", &num);

        if(findElement(root, num)){

            printf("\nElemento encontrado!\n");

        }else{

            printf("\nElemento nao encontrado!\n");

        }

    }else if(option == 4){
        
        aux = 0;

        printf("\n");
        printf("\n");
        
        printTreeTwoD(*root, aux);

    }
}

int EhArvoreArvl(treeNode **root){
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
