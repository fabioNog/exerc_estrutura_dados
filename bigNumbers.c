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
int somarDoisNumeros(struct Lista* lista1,struct Lista* lista2,struct Lista lista3);

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
	int n = 0;
	int tam1, tam2 = -1;
	int valor;
	printf("*********************************************** \n	");
	printf("Digite -1 duas vezes para finalizar o programa \n");
	printf("*********************************************** \n\n");
	while (n != -2)
	{
		printf("Digite um valor: ");
		scanf("%d", &valor);
		if (valor != -1 && n == 0)
		{
			inserirInicio(&lista1, valor);
			tam1++;
			continue;
		}
		else if (valor != -1 && n == -1)
		{
			inserirInicio(&lista2, valor);
			tam2++;
			continue;
		}

		else if (valor == -1 && n == 0)
		{
			n = n + valor;
			inserirInicio(&lista1, valor);
			tam1++;
			continue;
		}

		else if (valor == -1 && n == -1)
		{
			n = n + valor;
			inserirInicio(&lista2, valor);
			tam2++;
			continue;
		}
	}

	remover(&lista1, -1);
	remover(&lista2, -1);

	if (tam1 < tam2)
	{
		do
		{
			inserirFim(&lista1, 0);
			tam1++;
		} while (tam2 > tam1);
	}
	else
	{
		do
		{
			inserirFim(&lista2, 0);
			tam2++;
		} while (tam1 > tam2);
	}

	somarDoisNumeros(&lista1,&lista2,lista3);	


	return 0;
}

int somarDoisNumeros(struct Lista *lista1,struct Lista *lista2,struct Lista lista3){
	struct node *aux1 = lista1->inicio;
	struct node *aux2 = lista2->inicio;

	int soma;
	int vai_um = 0;

	while (aux1 != NULL)
	{

		soma = aux1->dado + aux2->dado + vai_um;

		if (soma < 10)
		{

			inserirInicio(&lista3, soma);
			vai_um = 0;
		}
		else
		{

			soma = ((aux1->dado + aux2->dado + vai_um) % 10);
			inserirInicio(&lista3, soma);
			vai_um = 1;
		}

		aux1 = aux1->prox;
		aux2 = aux2->prox;
	}

	if (vai_um == 1)
	{
		inserirInicio(&lista3, vai_um);
	}
	mostrar(lista3);
	return 1;
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

int inserirInicio(struct Lista *lista, int dado)
{
	struct node *novo = malloc(sizeof(struct node));

	if (novo == NULL)
		return 0;

	novo->dado = dado;

	if (lista->inicio == NULL)
	{
		lista->inicio = novo;
		lista->fim = novo;
		novo->prox = NULL;
		novo->ant = NULL;
	}
	else
	{
		novo->prox = lista->inicio;
		lista->inicio->ant = novo;
		novo->ant = NULL;
		lista->inicio = novo;
	}

	return 1;
}


int remover(struct Lista *lista, int dado)
{
	struct node *aux;
	int qtdDel = 0;

	aux = lista->inicio;

	while (aux != NULL)
	{
		if (aux->dado == dado)
		{
			qtdDel++;
			if (aux == lista->inicio)
			{
				lista->inicio = aux->prox;
				if (lista->inicio != NULL)
				{
					lista->inicio->ant = NULL;
				}
				free(aux);
				aux = lista->inicio;
			}
			else if (aux == lista->fim)
			{
				lista->fim = lista->fim->ant;
				lista->fim->prox = NULL;
				free(aux);
				aux = NULL;
			}
			else
			{
				aux->ant->prox = aux->prox;
				aux->prox->ant = aux->ant;
				struct node *aux2;
				aux2 = aux->prox;
				free(aux);
				aux = aux2;
			}
		}
		else
		{
			aux = aux->prox;
		}
	}

	return qtdDel;
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
