#if defined(__MINGW32__) || defined(_MSC_VER)
#define OS_Win
#else
#include <unistd.h>
#endif

struct dd{
    char nome[30];
    int idade;
}typedef dados;

struct nd{
    dados d;
    struct nd *ant;
    struct nd *prox;
}typedef nodo;

typedef struct{
    dados d;
    nodo *aux;
    nodo *aux2;
    int i, j;
    nodo *first;
    nodo *end;
}fila;

fila *createList();
int push(void *pBuffer);
int pop(void *pBuffer);
int empty(void *pBuffer);
void print(void *pBuffer);
void clear(void *pBuffer);
void readStr(char *name);
void menu(void *pBuffer);
void clearScreen();
void sort(void *pBuffer);
