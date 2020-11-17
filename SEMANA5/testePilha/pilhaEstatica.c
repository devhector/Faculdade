#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

typedef struct{
    char nome[30];
    int idade;
}dados;

typedef struct{
    dados d[MAX];
    int qtd;
}pilha;

pilha *criaLista();
void liberar(pilha *p, dados *d);
int cheio(pilha *p);
int vazio(pilha *p);
int inserir(pilha *p, dados *d);
int remover(pilha *p);
void imprime(pilha *p);
void menu(pilha *p, dados *d);
void readStr(char *name);


int main()
{
    pilha *p;
    dados *d = (dados *)malloc(sizeof(dados));

    p = criaLista();

    menu(p, d);

    liberar(p, d);
    
    return 0;
}

pilha *criaLista(){
    pilha *p;

    p = (pilha *)malloc(sizeof(pilha));

    if(p != NULL)
        p->qtd = 0;

    return p;
}

void liberar(pilha *p, dados *d){
    free(p);
    free(d);
}

int cheio(pilha *p){
    return p->qtd == MAX;
}

int vazio(pilha *p){
    return p->qtd == 0;
}

int inserir(pilha *p, dados *d){

    if(p == NULL)
        return 0;
    if(p->qtd == MAX)
        return 0;

    p->d[p->qtd] = *d;
    p->qtd++;

    return 1;
}

int remover(pilha *p){
    if(p == NULL || p->qtd == 0)
        return 0;

    p->qtd--;

    return 1;
}

void imprime(pilha *p){
    int i;

    if(p == NULL)
        return;

    for(i = (p->qtd - 1); i > -1; i--){
        printf("\nPessoa %d", i);
        printf("\nNome: %s.", p->d[i].nome);
        printf("\nIdade: %d", p->d[i].idade);
        printf("\n");
    }
    printf("Digite enter para continuar...");
    getchar();
}

void menu(pilha *p, dados *d){

    int op;

    do
    {
        system("clear");
        printf("\nPilha:\n");
        printf("\n1 - Inserir pessoa.");
        printf("\n2 - Remover o topo.");
        printf("\n3 - Imprimir.");
        printf("\n4 - Sair.");
        printf("\nDigite: ");
        scanf("%d", &op);

        setbuf(stdin, NULL);

        if(op == 1){
            printf("\nDigite o nome: ");
            readStr(d->nome);
            printf("\nDigite a idade: ");
            scanf("%d", &(*d).idade);
            inserir(p, d);
        }

        if(op == 2){
            remover(p);
            printf("\nTopo removido.");
            printf("\nAperte enter para sair...");
            getchar();
        }

        if(op == 3)
            imprime(p);

    
    } while (op != 4);
    
}

void readStr(char *name)
{

    char c;
    c = getchar();
    int i = 0;

    while (c != '\n')
    {
        name[i] = c;
        c = getchar();
        i++;
        if(i > 28) break;
    }
    name[i] = '\0';

}