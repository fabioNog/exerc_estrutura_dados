// Develop by Filipe Silva

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int value;
	struct Node *next;
	struct Node *prev;
} Node;

typedef struct List
{
	Node *start;
	Node *end;
	int quant;
} List;

void menu();
void initialize(List *list);
int insertNumbers(List *list);
int insert(List *list, int value);
int calcNumbers(List list, List list2, List result);
int print(List list);
void printResult(List list, List list2, List result);

int main()
{
	List numbers1;
	List numbers2;
	List result;

	initialize(&numbers1);
	initialize(&numbers2);
	initialize(&result);

	menu();

	insertNumbers(&numbers1);
	insertNumbers(&numbers2);

	calcNumbers(numbers1, numbers2, result);

	return 0;
}

void menu()
{
	printf("================================================================");
	printf("\n\t\t\tBigNumbers\n");
	printf("================================================================\n\n");
}
void initialize(List *list)
{
	list->start = NULL;
	list->end = NULL;
	list->quant = 0;
}
int insertNumbers(List *list)
{
	int value, quant = 0;
	do
	{
		Node *aux = malloc(sizeof(Node));
		if (aux == NULL)
			return -1;
		printf("Number: ");
		scanf("%d", &value);
		if (value != -1)
		{
			quant++;
			aux->value = value;
			if (list->start == NULL)
			{
				list->start = aux;
				list->end = aux;
				aux->next = NULL;
				aux->prev = NULL;
			}
			else
			{
				list->end->next = aux;
				aux->prev = list->end;
				aux->next = NULL;
				list->end = aux;
			}
			list->quant = quant;
		}
		else if (value == -1 && list->start == NULL)
		{
			aux->value = 0;
			list->start = aux;
			list->end = aux;
			aux->next = NULL;
			aux->prev = NULL;
			list->quant = 1;
		}
	} while (value != -1);
	return 0;
}
int insert(List *list, int value)
{
	Node *aux = malloc(sizeof(Node));
	if (aux == NULL)
		return 0;

	aux->value = value;
	if (list->start == NULL)
	{
		list->start = aux;
		list->end = aux;
		aux->next = NULL;
		aux->prev = NULL;
	}
	else
	{
		aux->next = list->start;
		aux->prev = NULL;
		list->start->prev = aux;
		list->start = aux;
	}
	return 1;
}
int calcNumbers(List list, List list2, List result)
{
	Node *aux, *aux2;
	int sum = 0, carry = 0;

	if (list.start == NULL && list2.start == NULL)
		return -1;

	if (list.quant >= list2.quant)
	{
		aux = list.end;
		aux2 = list2.end;
	}
	else
	{
		aux = list2.end;
		aux2 = list.end;
	}

	while (aux != NULL)
	{
		if (aux2 != NULL)
			sum = aux->value + aux2->value + carry;
		else
			sum = aux->value + carry;

		if (sum >= 10)
		{
			sum = sum % 10;
			carry = 1;
		}
		else
			carry = 0;

		insert(&result, sum);

		aux = aux->prev;
		if (aux2 != NULL)
			aux2 = aux2->prev;
	}
	printResult(list, list2, result);
	return 1;
}
int print(List list)
{
	Node *aux;

	if (list.start == NULL)
		return -1;
	aux = list.start;

	printf("\t\t\t");
	while (aux != NULL)
	{
		printf("%d", aux->value);
		aux = aux->next;
	}

	return 0;
}
void printResult(List list, List list2, List result)
{
	printf("\n================================================================\n");
	print(list);
	printf("\n");
	print(list2);
	printf("\t+\n\t---------------------------------------\n");
	print(result);
	printf("\n================================================================");
}
