#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct registro
{
    int id;
    char descricao[30];
} Registro;

void flush_in();
void ler(Registro *registro, int n);
void imprimir(Registro *registro, int n);
void ordena(Registro *registro, int n);
int binario(Registro *item, char *key, int tam);

int main()
{
    char key[30], search[30];
    int tam = 0;
    Registro *registro;

    printf("Quantidade: ");
    scanf("%d", &tam);
    flush_in();

    printf("Pesquisa: ");
    scanf("%s", search);
    flush_in();
    strcpy(key, search);

    int posicao = -1;

    registro = (Registro *)malloc(tam * sizeof(Registro));

    ler(registro, tam);
    ordena(registro, tam);
    imprimir(registro, tam);

    posicao = binario(registro, key, tam);
    printf("Localizado na posicao: %d\n", posicao);

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
        printf("Id: ");
        scanf("%d", &registro[i].id);
        flush_in();
        printf("Descricao: ");
        fgets(registro[i].descricao, sizeof(registro[i].descricao), stdin);
        registro[i].descricao[strcspn(registro[i].descricao, "\n")] = '\0';
    }
}

void imprimir(Registro *registro, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", registro[i].id);
        printf("%s\n", registro[i].descricao);
    }
}

void ordena(Registro *registro, int n)
{
    int contador, vezes, num;
    do
    {
        vezes = 0;
        for (contador = 0; contador < n - 1; contador++)
        {
            num = strlen(registro[contador].descricao);
            if (strncmp(registro[contador].descricao, registro[contador + 1].descricao, num) > 0)
            {
                Registro tmp = registro[contador];
                registro[contador] = registro[contador + 1];
                registro[contador + 1] = tmp;
                vezes++;
            }
        }
    } while (vezes > 0);
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
        { //if(strcmp(key,item[mid]) < 0)
            high = mid - 1;
        }
        else if (strcmp(key, item[mid].descricao) > 0)
        { //if(strcmp(key , item[mid]) > 0 )
            low = mid + 1;
        }
        else
        {
            return mid;
        }
    }

    return -1;
}