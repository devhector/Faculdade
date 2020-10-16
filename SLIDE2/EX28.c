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
    pessoa *pe = (pessoa *) malloc(sizeof(pessoa));
    int quest = 1, i = 0, j = 1;

    while(1){
        system("clear");
        printf("1 - adicionar nova pessoa/ 0 - sair. Digite: ");
        scanf("%d", &quest);
        if(!quest) break;

        setbuf(stdin, NULL);
        printf("\nDigite o nome da pessoa: ");
        fgets (&*(pe + i)->nome, 30, stdin);
        setbuf(stdin, NULL);
        printf("\nDigite a idade da pessoa: ");
        scanf("%d", &pe[i].idade);
        printf("\nDigite a altura da pessoa: ");
        scanf("%d", &pe[i].altura);
        i++;
        j++;
        
        pe = realloc(pe, sizeof(pessoa) * j);
        if(!pe){
            printf("ERRO DE MEMÓRIA!!\n");
            return -1;
        }


    }

    for(j = 0; j < i; j++){
        printf("\nPessoa - %d\n", j + 1);
        printf("Nome: %s", (pe + j)->nome);
        printf("Idade: %d\n", pe[j].idade);
        printf("Altura: %d\n", pe[j].altura);

    }

    free(pe);
    
    return 0;
}
