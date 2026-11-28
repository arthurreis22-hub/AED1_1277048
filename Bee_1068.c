/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : <<<Arthur Reis Martins>>>
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/<<1068>>
Data        : 24/11/2026
Objetivo    : verificar se os parentes estao condizentes
Dificuldade : <<<Leitura da entrada dar certo>>>
Uso de IA   : <<<Descobrir que existe um negocio chamado fgets>>>
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
	char valor;
	struct no *prox;
} No;

typedef struct {
	No *topo;
} Pilha;

void push(Pilha *p, char valor) {
	No *novo = malloc(sizeof(No));
	
	novo->valor = valor;
	novo->prox = p->topo;
	
	p->topo = novo;
}

void pop(Pilha *p) {
	No *aux;
	
	aux = p->topo;
	p->topo = p->topo->prox;
	
	free(aux);
}

void libera_pilha(Pilha *p) {
	while (p->topo != NULL) {
		pop(p);
	}
}

int main() {
    char expressao[1005];
    int i, correto;

    while (fgets(expressao, 1005, stdin) != NULL) {
        Pilha p;
        p.topo = NULL;

        correto = 1;

        for (i = 0; expressao[i] != '\0'; i++) {
            if (expressao[i] == '(') {
                push(&p, expressao[i]);
            }
            else if (expressao[i] == ')') {
                if (p.topo == NULL) {
                    correto = 0;
                    break;
                }
                else {
                    pop(&p);
                }
            }
        }

        if (p.topo != NULL) {
            correto = 0;
        }

        if (correto == 1) {
            printf("correct\n");
        }
        else {
            printf("incorrect\n");
        }

        libera_pilha(&p);
    }

    return 0;
}
