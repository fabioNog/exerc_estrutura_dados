#include <stdio.h>
#include <stdlib.h>

struct node
{
	int dado;
	struct node *prox;
	struct node *ant;
};

struct Lista
{
	struct node *inicio;
	struct node *fim;
} Lista;

void inicializar(struct Lista *lista);
int inserirInicio(struct Lista *lista, int dado);
int inserirFim(struct Lista *lista, int dado);
int inserirInicio(struct Lista *lista, int dado);
int mostrar(struct Lista lista);
int remover(struct Lista *lista, int dado);
int somaDoisNumeros(int n1, int n2);
void somaGrandesNumeros(struct Lista *lista1, struct Lista *lista2,struct Lista *lista3);

int main()
{

	int op;
	int dado;
	struct Lista lista1;
	struct Lista lista2;
	struct Lista lista3;

	inicializar(&lista1);
	inicializar(&lista2);
	inicializar(&lista3);

	printf("*********** Soma de grandes Numeros **********\n");
	int n = 0, valor;
	printf("*********************************************** \n	");
	printf("Digite -1 finalizar o programa \n");
	printf("*********************************************** \n\n");
	while (n != -2)
	{
		printf("Digite um valor: ");
		scanf("%d", &valor);
		if (valor != -1 && n == 0)
		{
			inserirFim(&lista1, valor);
			continue;
		}
		else if (valor != -1 && n == -1)
		{
			inserirFim(&lista2, valor);
			continue;
		}

		else if (valor == -1 && n == 0)
		{
			n = n + valor;
			inserirFim(&lista1, valor);
			continue;
		}

		else if (valor == -1 && n == -1)
		{
			n = n + valor;
			inserirFim(&lista2, valor);
			continue;
		}
	}

	somaGrandesNumeros(&lista1, &lista2,&lista3);
//	somaBig(&lista1, &lista2);
	/* printf("************ Lista 1 ************ \n");
	mostrar(lista1);
	printf("\n************ Lista 1 ************ \n");
	printf("\n************ Lista 2 ************ \n");
	mostrar(lista2);
	printf("\n************ Lista 2 ************ \n"); */

	return 0;
}

void inicializar(struct Lista *lista)
{
	lista->inicio = NULL;
	lista->fim = NULL;
}

int inserirFim(struct Lista *lista, int dado)
{
	struct node *novo = malloc(sizeof(struct node));
	if (novo == NULL)
		return 0;

	novo->dado = dado;

	if (lista->inicio == NULL)
	{
		lista->inicio = novo;
		lista->inicio->prox = NULL;
		lista->fim = novo;
		novo->prox = NULL;
		novo->ant = NULL;
	}
	else
	{
		lista->fim->prox = novo;
		novo->ant = lista->fim;
		novo->prox = NULL;
		lista->fim = novo;
	}

	return 1;
}

int inserirInicio(struct Lista *lista, int dado){
	struct node  *novo = malloc(sizeof(struct node));
	
	if(novo == NULL)
		return 0;

	novo->dado = dado;	
	
	if(lista->inicio == NULL){
		lista->inicio = novo;
		lista->fim = novo;
		novo->prox = NULL;
    novo->ant  = NULL;
	}else{
		novo->prox = lista->inicio;
    lista->inicio->ant = novo;
    novo->ant = NULL;
		lista->inicio = novo;
	}

	return 1;
}

void somaGrandesNumeros(struct Lista *lista1, struct Lista *lista2,struct Lista *lista3)
{
	int soma = 0;
	int recebe = 0;
	struct node *aux1 = lista1->fim->ant;
	struct node *aux2 = lista2->fim->ant;

	//Criar uma função para inserir na terceira lista os valores do somaDoisNumeros
	while (aux1 != NULL && aux2 != NULL)
	{
		if(aux1 == NULL && aux2 != NULL){
			recebe = somaDoisNumeros(0,aux2->dado);
			inserirInicio(lista3,recebe);
				
		}
		else if(aux1 != NULL && aux2 == NULL){
			recebe = somaDoisNumeros(aux1->dado,0);
		}
		else{
			recebe = somaDoisNumeros(aux1->dado,aux1->dado);
			if(recebe > 9){
				int resto = recebe % 10;
				int valorDadivisao = recebe/10;
				inserirInicio(lista3,resto);
			}
		}
		
		aux1 = aux1->ant;
		aux2 = aux2->ant;
	}

}

int somaDoisNumeros(int v1, int v2)
{
	int soma = v1 + v2;
	return soma;
}

int mostrar(struct Lista lista)
{
	struct node *aux;

	if (lista.inicio == NULL)
	{
		return 0;
	}
	else
	{
		aux = lista.inicio;
		while (aux != NULL)
		{
			printf("%d ", aux->dado);
			aux = aux->prox;
		}
	}
	return 1;
}
