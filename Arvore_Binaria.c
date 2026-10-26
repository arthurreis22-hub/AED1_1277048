#include <stdio.h>
#include <stdlib.h>

typedef struct no {
	int valor;
	struct no *esq;
	struct no *dir;
} No;

No *criar_no(int valor) {
	
	No *novo = malloc(sizeof(No));
	
	if (novo == NULL) {
		printf("Erro na alocacao de memoria!");
		// o exit(1) eh uma funcao da biblioteca stdlib.h, ela basicamente encerra o programa na hora devido a algum problema
		// nesse caso eh necessario fazer isso porque se colocassemos NULL, o codigo poderia interpretar que a arvore esta vazia
		// e n que houve um erro na alocacao de memoria (que eh o q aconteceu de verdade).
		return NULL;
	}
	
	novo->valor = valor;
	novo->esq = NULL;
	novo->dir = NULL;
	
	return novo;
}

No *inserir_valor(No *raiz, int valor) {
	
	if(raiz == NULL) {
		return criar_no(valor);
	}
	
	if (valor < raiz->valor) {
		raiz->esq = inserir_valor(raiz->esq, valor);
	}
	else if (valor > raiz->valor ) {
		raiz->dir = inserir_valor(raiz->dir, valor);
	}
	
	// como os valores digitados sao distintos, entao nao existe o caso de valor = raiz->valor
	
	return raiz;
}

void imprimir_valores(No *raiz) {
	if (raiz != NULL) {
		imprimir_valores(raiz->esq);
		printf("%d ", raiz->valor);
		imprimir_valores(raiz->dir);
	}
}

void liberar_memoria(No *raiz) {
	if (raiz != NULL) {
		liberar_memoria(raiz->esq);
		liberar_memoria(raiz->dir);
		free(raiz);
	}
}

int main(void) {
	
	No *raiz = NULL;
	
	int i, valor;
	
	for(i=0; i<5; i++) {
		if (scanf("%d", &valor) !=1) {
			printf("Entrada invalida!\n");
			liberar_memoria(raiz);
			return 1;
		} 
		
		raiz = inserir_valor(raiz, valor);
	}
	
	imprimir_valores(raiz);
	
	liberar_memoria(raiz);
	
	return 0;
}
