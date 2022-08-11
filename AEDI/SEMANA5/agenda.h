struct dado{
    char nome[30];
    int idade;
}typedef dados;

struct nodo{
    dados pessoa;
    struct nodo *ant;
    struct nodo *prox;
}typedef nodos;

typedef struct{
    int i;
    int j;
    int aux;
    int *ordem;
    int tamanho;
    int opcao;
    int prioridade;
    nodos *primeiro;
    nodos *ultimo;
}filas;

int empty(void *pBuffer);
int push(void * pBuffer);
int pop(void *pBuffer);
int tamanho(void *pBuffer); 
void print(void *pBuffer);
void menu(void *pBuffer);
void clear(void *pBuffer);
void imprimirOrdenado(void *pBuffer);
filas *createList();
