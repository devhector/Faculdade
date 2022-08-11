#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[30];
    int idade;
}dados;

struct pilha{
    dados pessoa;
    struct pilha* prox;
};

