#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[30];
    int idade;
}dados;

typedef struct{
    dados pessoa;
    struct elemento *prox;
}elemento;

typedef elemento* pilha;

pilha *reset();
void clear(pilha *topo);
int empety(pilha *topo);
int push(pilha *topo, dados d);
int pop(pilha *topo);
void print(pilha *topo);
void menu(pilha *topo);
void readStr(char *name);

int main()
{
    pilha *topo;

    topo = reset();

    menu(topo);

    free(topo);
    return 0;
}

pilha *reset(){
    pilha *topo = (pilha *)malloc(sizeof(pilha));
    
    if(topo != NULL) *topo = NULL;

    return topo;
}

void clear(pilha *topo){
    if(topo != NULL){
        elemento *no;

        while ((*topo) != NULL)
        {
            no = topo;
            topo = (*topo)->prox;
            free(no);
        }

        free(topo);
        
    }
}

int empety(pilha *topo){
    
    if(topo == NULL) return 1;
    if(*topo == NULL) return 1;

    return 0;
}

int push(pilha *topo, dados d){
    
    if(topo == NULL) return 0;
    elemento *no = (elemento *)malloc(sizeof(elemento));
    if(no == NULL) return 0;

    no->pessoa = d;
    no->prox = (*topo);
    *topo = no;

    return 1;
}

int pop(pilha *topo){

    if(empety(topo)) return 0;

    elemento *no = *topo;
    *topo = no->prox;
    free(no);

    return 1;
}

void print(pilha *topo){
    if(empety(topo)){ 
        
        printf("\nPilha vazia");
        printf("\nAperte enter para continuar...");
        getchar();
        return;

    }

    elemento *no;

    while ((*topo) != NULL){
        
        no = topo;
        topo = (*topo)->prox;

        printf("\n---------------------\n");
        printf("\nNome: %s", no->pessoa.nome);
        printf("\nIdade: %d\n", no->pessoa.idade);

    }

    printf("\n---------------------\n");

    free(no);
}

void menu(pilha *topo){
    int op;
    dados *d = (dados *)malloc(sizeof(dados));
    
    do
    {
        system("clear");
        printf("\nMenu: ");
        printf("\n0 - Insere pessoa");
        printf("\n1 - Deleta pessoa topo");
        printf("\n2 - Deleta pessoa por nome");
        printf("\n3 - Limpa pilha");
        printf("\n4 - Lista pessoas");
        printf("\n5 - Sair");
        printf("\nDigite: ");
        scanf("%d", &op);

        if(op == 0){
            printf("\n\nDigite o nome: ");
            readStr(d->nome);
            printf("\nDigite a idade: ");
            scanf("%d", &d->idade);
            push(topo, *d);
        }

        if(op == 1){
            if(!pop(topo)) printf("\n\nErro: pilha vazia. aperte enter para continuar.");
            else printf("\n\nPessoa deletada, aperte enter para continuar...");
            getchar();
        }

        if(op == 3){
            printf("\n\nPilha vazia, aperte enter para continuar...");
            clear(topo);
            getchar();
        }

        if(op == 4){
            print(topo);
            getchar();
        }

    } while (op != 5);
    


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