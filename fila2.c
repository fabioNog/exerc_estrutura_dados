#include <stdio.h>
#include <stdlib.h>

struct queue {
    int dado;
    struct queue *prox;   
};

struct fila{
    struct queue * inic;
    struct queue * fim;
};

typedef struct fila Fila;

void iniciar(Fila *F){
    F->inic = NULL;
    F->fim = NULL;
}

void insere(Fila *F,int valor){
    struct queue *novo;
    novo = (struct queue*)malloc(sizeof(struct queue()));

    if(novo == NULL){
        printf("Impossivel Alocar a memoria");
    }
    else{
        novo->dado = valor;
        novo->prox = NULL;

        if(F->inic == NULL){
            F->inic = novo;
            F->fim = novo;
        }
        else{
            F->fim->prox = novo;
            F->fim = novo;
        }
    }
}

int retira(Fila *F){
    struct queue *aux = F->inic;
    int rem = aux->dado;
    free(aux);
    return rem;
}

void apresentaFila(Fila* F){
    struct queue *aux = F->inic;   
    while(aux != NULL){
        printf("Dado : %3d\n",aux->dado);
        aux = aux->prox;
    }
}



int main(){
    Fila F1;

    iniciar(&F1);
    insere(&F1,5);
    apresentaFila(&F1);

    return 0;
}
