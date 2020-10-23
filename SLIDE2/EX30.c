#include <stdio.h>
#include <stdlib.h>

int **criaMatriz(int lin, int col);
void leiaMatriz(int **matriz, int lin, int col);
int somaMatriz(int **matriz, int lin, int col);
int *colunaMatriz(int **matriz, int lin, int col, int nColuna);
void liberaMatriz(int **matriz, int lin);
void imprimeMatriz(int **matriz, int lin, int col);
void imprimeVetor(int *vetor, int col);



int main()
{
    int **matriz, *vetor;
    int lin, col, nCol, op;


    while(1){
        system("clear");
        printf("\n1 - Criar ou redimensionar a matriz");
        printf("\n2 - Ler elementos da matriz");
        printf("\n3 - Soma dos elementos da matriz");
        printf("\n4 - Imprimir valores de uma coluna da matriz");
        printf("\n5 - Imprimir a matriz");
        printf("\n6 - Sair");
        
        printf("\nDigite uma opcao: ");
        do{
            scanf("%d", &op);
            setbuf(stdin, NULL);
            if(op < 1 || op > 6)
                printf("\nDigite uma opçao valida: ");
        }while(op < 1 || op > 6);

        if(op == 1){
            system("clear");
            printf("\nDigite a quantidade de linhas: ");
            scanf("%d", &lin);
            printf("\nDigite a quantidade de colunas: ");
            scanf("%d", &col);
            matriz = criaMatriz(lin, col);
        }

        if(op == 2){
            system("clear");
            leiaMatriz(matriz, lin, col);
        }

        if(op == 3){
            system("clear");
            printf("\nSoma de todos os elementos da matriz = %d", somaMatriz(matriz, lin, col));
            printf("\nAperte enter para continuar...");
            getchar();
        }

        if(op == 4){
            system("clear");
            printf("\nDigite a coluna que deseja imprimir: ");
            do
            {
                scanf("%d", &nCol);
                if(nCol < 1 || nCol > col)
                    printf("\nDigite um valor valido entre 1 e %d: ", col);
            } while (nCol < 1 || nCol > col);
            
           // vetor = (int *)malloc(sizeof(int) * lin);
            vetor = colunaMatriz(matriz, lin, col, (nCol - 1));
            imprimeVetor(vetor, lin); 
            printf("\nAperte enter para continuar...");
            getchar();
        }

        if(op == 5){
            system("clear");
            imprimeMatriz(matriz, lin, col);
            printf("\nAperte enter para continuar...");
            getchar();
        }

        if(op == 6)
            break;
    }
    liberaMatriz(matriz, lin);
    free(vetor);
    return 0;
}

int **criaMatriz(int lin, int col){
    int **matriz = (int **)malloc(sizeof(int *) * lin), 
        i;


        for(i = 0; i < lin; i++){
            matriz[i] = (int *)malloc(col * sizeof(int));
        }


    return matriz;

}

void leiaMatriz(int **matriz, int lin, int col){
    int i, j;

    for(i = 0; i < lin; i++){
        for(j = 0; j < col; j++){
            printf("\nDigite o valor da linha: %d | coluna: %d: ", i + 1, j + 1);
            scanf("%d", &matriz[i][j]);
        }
        printf("\n");
    }
}

int somaMatriz(int **matriz, int lin, int col){
    int aux = 0;
    int i, j;
    
    for(i = 0; i < lin; i++)
        for(j = 0; j < col; j++)
            aux+= matriz[i][j];

    return aux;
}

int *colunaMatriz(int **matriz, int lin, int col, int nColuna){
    int *vetor = (int *)malloc(lin *  sizeof(int));
    int i, j, k = 0;

    for(i = 0; i < lin; i++)
        for(j = 0; j < col; j++){
            if(j == nColuna){
                vetor[k] = matriz[i][j];
                k++;
            }
        }
    return vetor;
}

void liberaMatriz(int **matriz, int lin){
    int i;

    for(i = 0; i < lin; i++)
        free(matriz[i]);

    free(matriz);
}

void imprimeMatriz(int **matriz, int lin, int col){
    int i, j;

    for(i = 0; i < lin; i++){
        for(j = 0; j < col; j++){
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

void imprimeVetor(int *vetor, int col){
    int i;

    for(i = 0; i < col; i++)
        printf("%d\t", vetor[i]);

}