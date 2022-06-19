#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node{   

    int dado;   
    struct node *prox;
};

struct Lista{

    struct node *inicio;
	struct node *fim;
};

void inicializar(struct Lista *lista);
int inserirInicio(struct Lista *lista, int dado);
int inserirFim(struct Lista *lista, int dado);
int remover(struct Lista *lista, int dado);
int mostrar(struct Lista lista);

int main(){

    int dado = 0, tamN1 = -1, tamN2 = -1;

	struct Lista listaN1;
	struct Lista listaN2;
	inicializar(&listaN1);
	inicializar(&listaN2);

    do{

        scanf("%d", &dado);
        inserirInicio(&listaN1, dado);
		tamN1++;
    }while(dado != -1);

	dado = 0;

	do{

        scanf("%d", &dado);
        inserirInicio(&listaN2, dado);
		tamN2++;
    }while(dado != -1);

	remover(&listaN1, -1);
	remover(&listaN2, -1);

	if(tamN1 > tamN2){

		do{

			inserirFim(&listaN2, 0);
			tamN2++;
		}while(tamN1 > tamN2);

	}else if (tamN2 > tamN1){

		do{

			inserirFim(&listaN1, 0);
			tamN1++;
		}while(tamN2 > tamN1);
	}

	struct node *auxN1 = listaN1.inicio;
	struct node *auxN2 = listaN2.inicio;

	struct Lista resposta;
	inicializar(&resposta);

	int soma;
	int vai_um = 0;

	while(auxN1 != NULL){

		soma = auxN1->dado + auxN2->dado + vai_um;

		if(soma < 10){

			inserirInicio(&resposta, soma);
			vai_um = 0;
		}else{

			soma = ((auxN1->dado + auxN2->dado + vai_um) % 10);
			inserirInicio(&resposta, soma);
			vai_um = 1;
		}

		auxN1 = auxN1->prox;
		auxN2 = auxN2->prox;
	}

	if(vai_um == 1){

		inserirInicio(&resposta, vai_um);
	}

	mostrar(resposta);

	return 0;
}

void inicializar(struct Lista *lista){

	lista->inicio = NULL;   
	lista->fim = NULL;   
}   

int inserirInicio(struct Lista *lista, int dado){
	struct node  *novo = malloc(sizeof(struct node));
	
	if(novo == NULL)
		return 0;

	novo->dado = dado;	
	
	if(lista->inicio == NULL){
		lista->inicio = novo;
		lista->fim = novo;
		lista->fim->prox = NULL;
	}else{
		novo->prox = lista->inicio;
		lista->inicio = novo;
	}

	return 1;
}

int inserirFim(struct Lista *lista, int dado){

	struct node  *novo = malloc(sizeof(struct node));
	novo->dado = dado;	
	
	if(novo == NULL){

		return 0;
	}
	if(lista->inicio == NULL){

		lista->inicio = novo;
		lista->fim = novo;
		lista->fim->prox = NULL;
	}else{

		lista->fim->prox = novo;
		lista->fim = novo;
		lista->fim->prox = NULL;
	}

	return 1;
}

int remover(struct Lista *lista, int dado){
	struct node *aux;
	struct node *ant;
	int qtdDel = 0;
	
	aux = lista->inicio;
	ant = NULL;

	while(aux != NULL){
		if(aux->dado == dado){
			qtdDel++;
			if(aux == lista->inicio){
				lista->inicio = aux->prox;
				free(aux);
				aux = lista->inicio;
			}else if(aux == lista->fim){
				ant->prox = NULL;
				lista->fim = ant;
				free(aux);
				aux = NULL;
			}else{
				ant->prox = aux->prox;
				free(aux);
				aux = ant->prox;
			}
		}else{
			ant = aux;
			aux = aux->prox;
		}
	}
	
	return qtdDel;
}

int mostrar(struct Lista lista){

	struct node *aux;	
	
	if(lista.inicio == NULL){

		return 0;	
	}else{

		aux = lista.inicio;
		while(aux != NULL){

			printf("%d", aux->dado);
			aux = aux->prox;
		}
	}

	return 1;
}