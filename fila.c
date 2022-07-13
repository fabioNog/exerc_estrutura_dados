#include<stdio.h>
#include<stdlib.h>

struct queue {
    int dado;
    struct queue * prox;
};
        
struct fila {
    struct queue *inicio;
    struct queue *fim;
};

void inicia ( struct fila * f ){
    f->inicio = NULL;
    f->fim = NULL;
}

void insere ( struct fila * f , int valor ){
	struct queue *novo;
	if ((novo = (struct queue*) malloc(sizeof( struct queue)))==NULL)
		printf ("Impossível alocar a memoria\n");
	else {
		novo->dado = valor;
		novo->prox = NULL;

		if (f->inicio == NULL) {
			f->inicio = novo;
			f->fim = novo;
		}
		else {
			(f->fim)-> prox = novo;
			f->fim = novo;
		}
	}							
}

int retira ( struct fila * f ) {
   
    struct queue *aux = f->inicio;
    int rem = aux->dado;
    f->inicio = aux->prox;
    free(aux);
    return rem; 
}

void apresentaFila( struct fila *f)
{
     struct queue *aux;
     aux = f->inicio;
 
     while(aux != NULL)
     {
         printf ("Dado = %3d\n",(aux->dado));
       	aux = aux->prox;
       
	 }
    
}
int main(){

    struct fila f;
    inicia(&f);
    insere(&f,10);
    getchar();
    apresentaFila(&f);
    insere(&f,7);
    insere(&f,8);
    insere(&f,1);
    
    getchar();
    apresentaFila(&f);
    printf("retira = %d\n",retira(&f));
    getchar();
    printf("retira = %d\n",retira(&f));
    getchar();
    printf("retira = %d\n",retira(&f));
    apresentaFila(&f);
    printf("retira = %d\n",retira(&f));
    apresentaFila(&f);
    getchar();
    return 0;
}