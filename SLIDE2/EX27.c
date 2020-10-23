#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *realocar(void *ponteiro, size_t tam);

int main()
{
    int *vet = (int *)malloc(sizeof(int));
    int op, i;
    char *str = (char *)malloc(sizeof(char)), aux[15];

    printf("\nDigite o tamanho do vetor: ");
    scanf("%d", &op);

    vet = (int *)realocar(vet, sizeof(int) * op);

    for(i = 0; i < op; i++){
        printf("\nDigite o valor da pos %d: ", i + 1);
        scanf("%d", &vet[i]);
    }
    setbuf(stdin, NULL);

    printf("\nDigite um nome: ");
    fgets(aux, 15, stdin);

    str = (char *)realocar(str, strlen(aux) * sizeof(aux));

    strcpy(str, aux);

    printf("\n");

    for(i = 0; i < op; i++)
        printf("%d - %s\n", vet[i], str);

    printf("\n");
    printf("\n");
 

    free(vet);
    free(str);

    
    return 0;
}

void *realocar(void *ponteiro, size_t tam){
    void *buffer;

    buffer = malloc(tam * sizeof(ponteiro));

    memcpy(buffer, ponteiro, tam);
    free(ponteiro);
    return buffer;
}
