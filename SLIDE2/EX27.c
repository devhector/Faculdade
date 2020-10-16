#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *realocar(void *ponteiro, size_t tam);

int main()
{
    int *vet = (int *)malloc(sizeof(vet));

    vet[0] = 1;

    vet = (int *) realocar(vet, 3 * sizeof(vet));

    
    vet[1] = 2;
    vet[2] = 3;

    printf("%d %d %d\n", vet[0],vet[1],vet[2]);

    free(vet);
    
    return 0;
}

void *realocar(void *ponteiro, size_t tam){
    void *buffer;

    buffer = malloc(tam * sizeof(buffer));

    memcpy(buffer, ponteiro, tam);
    free(ponteiro);
    return buffer;
}
