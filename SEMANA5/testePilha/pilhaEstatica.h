
pilha *criaLista(){
    pilha *p;

    p = (pilha *)malloc(sizeof(pilha));
    if(p != NULL) p->qtd = 0;

    return p;
}

void liberar(pilha *p){
    free(p);
}

