#include <stdio.h>
#include <stdlib.h>

struct queue{
    int dado;
    int tam;
    struct queue *prox;
};

struct fila{
    struct queue *inicio;
    struct queue *fim;
};

typedef struct fila Fila;

void iniciaFila(Fila *f){
    f->inicio = NULL;
    f->fim = NULL;
}

void insere(Fila *f,int dado){
    Fila *novo;

    if((novo = (struct queue*) malloc(sizeof (struc queue))) == NULL){
        printf("Impossivel alocar a memoria");
    }
}


int main(){
    printf("Hello World");

    return 0;
}