#include <stdio.h>
#include <stdlib.h>

void pop(int *vet, int op);

int main()
{
    int *vet, op, i;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &op);

    vet = (int *)malloc(op * sizeof(int));

    for(i = 0; i < op; i++){
        printf("\nDigite o valor da pos %d: ", i + 1);
        scanf("%d", &vet[i]);
    }

   printf("\nVetor original: ");
    for(i = 0; i < op; i++)
        printf("%d ", vet[i]);

    printf("\n");
    printf("\nVetor modificado: ");
    pop(vet, op);


    free(vet);
    return 0;
}

void pop(int *vet, int op){
    int tmp = op, i, j, k;

    for(i = 0; i < tmp; i++) {
        
        j = i + 1;
        while(j < tmp){

            if(vet[j] == vet[i]){

                for(k = j; k < tmp; k++){

                    vet[k] = vet[k + 1];

                }

                tmp--;

            }else{

                j++;
                
            }
        }
    }

    for(i = 0; i < tmp; i++)
        printf("%d ", vet[i]);

    printf("\n");
}