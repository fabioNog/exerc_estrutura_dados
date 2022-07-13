#include <stdio.h>
#include <stdlib.h>

struct node
{
    int dado;
    struct node *prox;
};

struct lista
{
    struct node *inic;
    struct node *fim;
};

typedef struct lista Lista;

void inicializar(Lista *L);

int inserirInicio(Lista *L, int dado);
int inserirFim(Lista *L, int dado);
void mostrar(Lista *lista);
int remover(Lista *L, int dado);
int menu();

int menu()
{
    int op;
    printf("\n 1 - Inserir no Inicio");
    printf("\n 2 - Inserir no Fim");
    printf("\n 3 - Mostrar Lista");
    printf("\n 4 - Remover itens");
    printf("\n 5 - Sair\n");
    scanf("%d", &op);
    return op;
}

void inicializar(Lista *L)
{
    L->fim == NULL;
    L->inic == NULL;
}

int inserirInicio(Lista *L, int dado)
{
    struct node *novo;
    novo = (struct node *)malloc(sizeof(struct node));
    if (novo == NULL)
    {
        return 0;
    }
    else
    {
        novo->dado = dado;

        if (L->inic == NULL)
        {
            L->inic = novo;
            L->fim = novo;
            L->fim->prox = NULL;
        }
        else
        {
            novo->prox = L->inic;
            L->inic = novo;
        }

        return 1;
    }
}

int inserirFim(Lista *L, int dado)
{
    struct node *novo;
    novo = (struct node *)malloc(sizeof(struct node));
    if (novo == NULL)
    {
        return 0;
    }
    else
    {
        novo->dado = dado;
        if (L->fim == NULL)
        {
            L->inic = novo;
            L->fim = novo;
            L->fim->prox = NULL;
        }
        else
        {
            L->fim->prox = novo;
            L->fim = novo;
            L->fim->prox = NULL;
        }

        return 1;
    }
}

int remover(Lista *L, int dado)
{
    struct node *aux;
    struct node *ant;
    int qtdDel = 0;

    aux = L->inic;
    ant = NULL;

    while (aux != NULL)
    {
        if (aux->dado == dado)
        {
            qtdDel++;
            if (aux == L->inic)
            {
                L->inic = aux->prox;
                free(aux);
                aux = L->inic;
            }
            else if (aux == L->fim)
            {
                ant->prox = NULL;
                L->fim = ant;
                free(aux);
                aux = NULL;
            }
            else
            {
                ant->prox = aux->prox;
                free(aux);
                aux = ant->prox;
            }
        }
        else
        {
            ant = aux;
            aux = aux->prox;
        }
    }

    return qtdDel;
}

void mostrar(Lista *Lista)
{
    struct node *aux = Lista->inic;
    if (aux == NULL)
    {
        printf("Nenhum elemento na lista");
    }
    while (aux != NULL)
    {
        printf("Valor: %3d\n", aux->dado);
        aux = aux->prox;
    }
}
// Main
int main()
{
    int op;
    int dado;
    struct lista L;
    inicializar(&L);

    do
    {
        op = menu();
        switch (op)
        {
        case 1:
            printf("Digite um numero: ");
            scanf("%d", &dado);
            if(inserirInicio(&L,dado))
                printf("Insercao Realizada com Sucesso");
            else
                printf("Falha na Insercao");                
            break;

        case 2:
            printf("Digite um numero: ");
            scanf("%d", &dado);
            if(inserirFim(&L,dado))
                printf("Insercao Realizada com Sucesso");
            else
                printf("Falha na Insercao");                
            break;
        case 3: 
            mostrar(&L);
            break;
        case 4:
            printf("Digite o valor a ser Removido\n");
            scanf("%d", &dado);
            printf("\n%d removidos!!!", remover(&L,dado));
            break;
        case 5:
            printf("\nTchau!!!");
			break; 
        default:
            printf("\nOpcao Invalida!!!");
            break;
        }

    } while (op != 5);
    return 0;
}