#include<stdio.h>
#include<stdlib.h>
typedef struct{
    char nome[30];
    int idade;
    float altura;
} Pessoa;

int main()
{
    Pessoa *p;
    int controle;
    int quantidade=1;
    int i=0;
    p = (Pessoa *) malloc(sizeof(Pessoa)); //alocando a primeira
    if(!p){
        printf("ERRO! Falta memória");
        return -1;
    }
    for(i=0;i<quantidade;i++)
    {
        printf("Digite 0 para sair\n");
        printf("Digite outro numero para continuar\n");
        scanf("%d",&controle);
        if(controle==0) break;
        printf("Digite o nome da pessoa\n");
        scanf("%s",&*(p[i]).nome);
        printf("Digite a idade da pessoa\n");
        scanf("%d",& p[i].idade);
        printf("Digite a altura da pessoa\n");
        scanf("%f",& p[i].altura);
        getchar();
        quantidade++;
        p = realloc(p,(sizeof(Pessoa)*quantidade));
        
    }
    for(i=0;i<quantidade-1;i++)
    {
        printf("Pessoa %d\n",i);
        printf("Nome:\t%s\n",(p[i]).nome);
        printf("Idade:\t%d\n",(p[i]).idade);
        printf("Altura:\t%.2f\n",(p[i]).altura);
        printf("\n");
    }
    free(p);
    return 0;
}