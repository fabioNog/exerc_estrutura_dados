#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct registro
{
    int id;
    char descricao[50];
} Registro;

void flush_in();
void ler(Registro *registro, int n);
void imprimir(Registro *registro, int n);
void swap(Registro* a, Registro* b);
int partition (Registro arr[], int low, int high);
void quickSort(Registro arr[], int low, int high);
int binario(Registro *item, char *key, int tam);

void swap(Registro* a, Registro* b) 
{ 
    Registro t = *a; 
    *a = *b; 
    *b = t; 
} 

int partition (Registro arr[], int low, int high) 
{ 
    char pivot[50] ; 
    strcpy(pivot, arr[high].descricao);
    int i = (low - 1); 
  
    for (int j = low; j <= high- 1; j++) 
    { 
        if (strcmp(arr[j].descricao , pivot) <= 0) 
        { 
            i++;  
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
  
void quickSort(Registro arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        int pi = partition(arr, low, high); 
        
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 

int main()
{
    char key[50];
    int tam = 0;
    Registro *registro;

    //printf("Quantidade: ");
    scanf("%d", &tam);
    flush_in();

    //printf("Pesquisa: ");
    fgets(key, 50, stdin);
    key[strcspn(key, "\n")] = '\0';

    int posicao = -1;

    registro = (Registro *)malloc(tam * sizeof(Registro));

    ler(registro, tam);
    quickSort(registro,0,tam-1);
    //imprimir(registro, tam);

    posicao = binario(registro, key, tam);
    printf("%d\n", posicao);

    free(registro);

    return 0;
}

void flush_in()
{
    int ch;

    while ((ch = fgetc(stdin)) != EOF && ch != '\n')
    {
    }
}

void ler(Registro *registro, int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &registro[i].id);
        flush_in();
        fgets(registro[i].descricao, 50, stdin);
        registro[i].descricao[strcspn(registro[i].descricao, "\n")] = '\0';
    }
}

void imprimir(Registro *registro, int n)
{
    //printf("----------TESTE----------\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", registro[i].id);
        printf("%s\n", registro[i].descricao);
    }
    //printf("-----RESPOSTA-----\n");
}

int binario(Registro *item, char *key, int tam)
{
    int low, high, mid;
    low = 0;
    high = tam - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (strcmp(key, item[mid].descricao) < 0)
        {
            high = mid - 1;
        }
        else if (strcmp(key, item[mid].descricao) > 0)
        {
            low = mid + 1;
        }
        else
        {
            return item[mid].id;
        }
    }

    return -1;
}
