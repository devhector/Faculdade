#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    char nome[30];
    int idade;
    int altura;

}pessoa;


int main()
{
    pessoa *pe = (pessoa *) malloc(sizeof(pessoa)), *buffer;
    int quest = 1, i = 0, j = 1;

    while(1){
        system("clear");
        printf("1 - adicionar nova pessoa/ 0 - sair. Digite: ");
        scanf("%d", &quest);
        if(!quest) break;

        printf("\nDigite o nome da pessoa: ");
        scanf("%s", &*(pe[i]).nome);
        printf("\nDigite a idade da pessoa: ");
        scanf("%d", &pe[i].idade);
        printf("\nDigite a altura da pessoa: ");
        scanf("%d", &pe[i].altura);
        i++;
        j++;
        
        buffer = realloc(pe, sizeof(pessoa) * j);
        if(!buffer){
            printf("ERRO DE MEMÓRIA!!\n");
            return -1;
        }
        pe = buffer;

    }

    for(j = 0; j < i; j++){
        printf("\nPessoa - %d\n", j + 1);
        printf("Nome: %s\n", (pe[i]).nome);
        printf("Idade: %d\n", (pe[i]).idade);
        printf("Altura: %d\n", (pe[i]).altura);

    }

    free(pe);
    free(buffer);    
    return 0;
}
