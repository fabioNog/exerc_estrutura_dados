// Develop by Filipe Silva

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int dado;
	struct Node *next;
} Node;

typedef struct List
{
	Node *start;
	Node *end;
} List;

void initialize(List *list);
int insert(List *list, int dado);

int main()
{
	List *number1;
	List *number2;

	initialize(&number1);
	initialize(&number2);

	return 0;
}

void initialize(List *list)
{
	list->start = NULL;
	list->end = NULL;
}
int insert(List *list, int dado)
{
	Node *aux = malloc(sizeof(Node));
	if (aux == NULL)
		return -1;

	aux->dado = dado;
	if (list->start == NULL)
	{
		list->start = aux;
		list->end = aux;
		aux->next = NULL;
	}
	else
	{
	}

	return 0;
}