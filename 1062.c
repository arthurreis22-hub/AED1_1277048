/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : <<<Arthur Reis Martins>>>
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/<<1062>>
Data        : 26/11/2026
Objetivo    : verificar as possibilidades e se aas sequencias sao possiveis mesmo ou n
Dificuldade : <<<ficar alternando entre pop e push pra conseguir verificar a sequencia dos vagoes>>>
Uso de IA   : <<<entender melhor justamente quando alternar as funcoes, e o pq disso>>>
-------------------------------------------------------------------------- */


#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
} No;

typedef struct {
    No *topo;
} Pilha;

void push(Pilha *p, int valor) {
    No *novo = malloc(sizeof(No));

    novo->valor = valor;
    novo->prox = p->topo;
    p->topo = novo;
}

void pop(Pilha *p) {
    No *aux = p->topo;

    p->topo = p->topo->prox;
    free(aux);
}

int top(Pilha *p) {
    if (p->topo == NULL) {
        return -1;
    }

    return p->topo->valor;
}

void libera_pilha(Pilha *p) {
    while (p->topo != NULL) {
        pop(p);
    }
}

int main() {
    int n, i, proximo;
    int permutacao[1005];
    int primeiro_bloco = 1;
    int possivel;
    Pilha p;

    while (scanf("%d", &n) == 1 && n != 0) {

        if (!primeiro_bloco) {
            printf("\n");
        }

        primeiro_bloco = 0;

        while (scanf("%d", &permutacao[0]) == 1 && permutacao[0] != 0) {

            for (i = 1; i < n; i++) {
                scanf("%d", &permutacao[i]);
            }

            p.topo = NULL;
            proximo = 1;
            possivel = 1;

            for (i = 0; i < n; i++) {

                while (top(&p) != permutacao[i] && proximo <= n) {
                    push(&p, proximo);
                    proximo++;
                }

                if (top(&p) == permutacao[i]) {
                    pop(&p);
                }
                else {
                    possivel = 0;
                    break;
                }
            }

            if (possivel) {
                printf("Yes \n");
            }
            else {
                printf("No \n");
            }

            libera_pilha(&p);
        }
    }

    return 0;
}

