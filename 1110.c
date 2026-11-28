/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : <<<Arthur Reis Martins>>>
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/<<1110>>
Data        : 23/11/2026
Objetivo    : Remove uma carta do topo e depois colocar a nova carta na base de uma pilha de cartas, varias vezes ate n ter mais como
Dificuldade : <<<Entender o problema e oque ele quer, bem confuso>>>
Uso de IA   : <<<Compreender melhor que nao era pra usar pilha, e sim fila>>>
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
	int valor;
	struct no *prox;
} No;

typedef struct {
	No *inicio;
	No *fim;
} Fila;

void insere_final(Fila *f, int valor) {
	No *novo = malloc(sizeof(No));
	
	novo->valor = valor;
	novo->prox = NULL;
	
	if (f->inicio == NULL) {
		f->inicio = novo;
	}
	else {
		f->fim->prox = novo;
	}
	
	f->fim = novo;
}

int remove_inicio(Fila *f) {
	// aq estamos tirando oq estava no topo da pilha de cartas, e colocando que o novo cara no topo eh aquele que estava depois (o proximo) do que foi removido, e devolvendo o valor da carta removida
	No *aux;
	int valor;
	
	aux = f->inicio;
	valor = aux->valor;
	
	f->inicio = f->inicio->prox;
	
	if (f->inicio == NULL) {
		f->fim = NULL;
	}
	free(aux);
	
	return valor;
}

int main() {
	int n, i, movida, qtd_descartadas;
	int descartadas[50];
	
	while (scanf("%d", &n) == 1 && n != 0) {
		Fila f;
		
		f.inicio = NULL;
		f.fim = NULL;
		
		qtd_descartadas = 0;
		
		for(i =1; i <= n; i++) {
			insere_final(&f, i);
		}
			while (f.inicio != f.fim) {
			descartadas[qtd_descartadas] = remove_inicio(&f);
			qtd_descartadas++;
			
			movida = remove_inicio(&f);
			insere_final(&f, movida);
		}
		
		printf("Discarded cards:");
		
		for(i=0; i<qtd_descartadas; i++){
			if (i>0) {
				printf(",");
			}
			
			printf(" %d", descartadas[i]);
		}
		
		printf("\nRemaining card: %d\n", f.inicio->valor);
		
		remove_inicio(&f);
	}
	
	return 0;
}
