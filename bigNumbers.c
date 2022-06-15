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
int mostrar(struct Lista lista);
int remover(struct Lista *lista, int dado);
int somaDoisNumeros(struct Lista *lista1, struct Lista *lista2);
int somaGrandesNumeros(struct Lista *lista1, struct Lista *lista2);

int main()
{

	int op;
	int dado;
	struct Lista lista1;
	struct Lista lista2;
	struct Lista lista3;

	inicializar(&lista1);
	inicializar(&lista2);

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

	somaGrandesNumeros(&lista1, &lista2);
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

int somaGrandesNumeros(struct Lista *lista1, struct Lista *lista2)
{
	int soma = 0;
	struct node *aux1 = lista1->fim->ant;
	struct node *aux2 = lista2->fim->ant;

	//Criar uma função para inserir na terceira lista os valores do somaDoisNumeros
	while (aux1 != NULL || aux2 != NULL)
	{
		soma += somaDoisNumeros(&aux1, &aux2);
		aux1 = aux1->fim->ant;
		aux2 = aux2->fim->ant;
	}

	return soma;
}

int somaDoisNumeros(struct Lista *l1, struct Lista *l2)
{
	if (l1 != NULL && l2 != NULL)
	{
		printf("Entrei aqui n1");
	}
	else if (l1 == NULL && l2 != NULL)
	{
		printf("Entrei aqui n2");
	}
	else if (l1 != NULL && l2 == NULL)
	{
		printf("Entrei aqui n3");
	}
	else
	{
		return 0;
	}
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
