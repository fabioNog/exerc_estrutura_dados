/* 
Números Gigantes
Você foi contrato para implementar um solução que permita a soma de
grandes números. 
Os números podem ter até 10 milhões de digitos e será
necessário uma abordagem diferente de apenas somar n1 com n2. 
A equipe de requisitos enviou alguns exemplos para 
auxiliá-los a pensar na solução.
Considere a primeira entrada apresentada abaixo. 
O primeiro número nessa entrada
(N1) é 345. 
Observe que o -1 deve ser descartado no processo de leitura. 
Após a leitura do primeiro valor -1 
tem-se início a leitura dos valores referentes ao
segundo número N2 que ocorre até um novo valor -1 ser encontrado. 

Dicas:
• Realize a soma posição a posição e 
    implemente uma variável ((carry) ou vai-um).
Entrada:
• A entrada consiste de N1 inteiros 
entre 0 e 9 que determinam o primeiro
número. O fim dessa sequência é identificado pelo número -1. 
Em seguida, uma nova série de N2 números entre 0 e 9 
informam o segundo número.
Essa sequência é finalizada com a leitura de um novo valor -1.
Saída:
• A saída consiste na impressão do resultado da soma 
de N1 e N2 impressa sem espaçoos e com um salto de linha no final.


Exemplos de Entrada | Exemplo de saída
3 4 5 -1 1 0 -1     |  355 
1 1 -1 1 -1         |  12    
1 2 4 -1 7 6 -1     |  200

*/




#include <stdio.h>
#include <stdlib.h>

 struct node {   
  int dado;   
  struct node *prox;   
};

struct Lista{
   struct node *inicio;
	struct node *fim;
} Lista;

void inicializar(struct Lista *lista);
int inserirInicio(struct Lista *lista, int dado);
int inserirFim(struct Lista *lista, int dado);
int mostrar(struct Lista lista);
int remover(struct Lista *lista, int dado);
int menu();

int main(){

  int op;
	int dado;
	struct Lista lista;

	inicializar(&lista);	

    printf("*********** Soma de grandes Numeros ********** ");
    int n = 0,valor;
    printf("Digite -1 finalizar o programa");    
    while(n != -2){
        printf("Digite um valor: ");
        scanf("%d",&valor);
        if(valor == -1  && n == 0){
            n = n + valor;
        }
        else if(valor == -1  && n == -1){
            n = -2;
        }
        
    }

	do{
		op = menu();
		switch(op){
			case 1:  printf("Digite um numero: ");
						scanf("%d", &dado);
						if(inserirFim(&lista, dado))
							printf("Insercao realizado com sucesso!");
						else
							printf("Falha na insercao!");
						break;
			case 2:	mostrar(lista);
						break;
			case 3:  printf("Digite um numero: ");
						scanf("%d", &dado);
						printf("\n%d removidos!!!", remover(&lista,dado));
						break;
			case 4:	printf("\nTchau!!!");
						break;
			default: printf("\nOpcao Invalida!!!");
		}

	}while(op != 4);
	
	return 0;
}

int menu(){
	int op;
	printf("\n 1 - Inserir no Inicio");
	printf("\n 2 - Inserir no Fim");
	printf("\n 3 - Mostrar Lista");
	printf("\n 4 - Remover itens");
	printf("\n 5 - Sair\n");
	scanf("%d", &op);
	return op;
}

void inicializar (struct Lista *lista){   
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
	
	if(novo == NULL)
		return 0;

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
			printf("%d ", aux->dado);
			aux = aux->prox;
		}
	}
	return 1;
}



