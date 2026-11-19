/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : <<<Arthur Reis Martins>>>
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/<<1610>>
Data        : 18/11/2026
Objetivo    : Verificar se tem ciclos na dependencia dos documentos
Dificuldade : <<<Usar DFS em um grafo direcionado para identificar esses ciclos>>>
Uso de IA   : <<<Como saber q a dependencia de um documento ja voltou e ja tinha sido visitada>>>
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

int *visitado;
int *inicio;
int *destino;
int *prox;
int arestas;

int dfs(int u) {
    int i, v;

    visitado[u] = 1;

    for (i = inicio[u]; i != -1; i = prox[i]) {
        v = destino[i];

        if (visitado[v] == 1)
            return 1;

        if (visitado[v] == 0) {
            if (dfs(v))
                return 1;
        }
    }

    visitado[u] = 2;

    return 0;
}

int main() {
    int T, N, M;
    int i, A, B, ciclo;

    scanf("%d", &T);

    while (T--) {
        scanf("%d %d", &N, &M);

        visitado = calloc(N + 1, sizeof(int));
        inicio = malloc((N + 1) * sizeof(int));
        destino = malloc(M * sizeof(int));
        prox = malloc(M * sizeof(int));

        for (i = 1; i <= N; i++)
            inicio[i] = -1;

        arestas = 0;

        for (i = 0; i < M; i++) {
            scanf("%d %d", &A, &B);

            destino[arestas] = B;
            prox[arestas] = inicio[A];
            inicio[A] = arestas;

            arestas++;
        }

        ciclo = 0;

        for (i = 1; i <= N && !ciclo; i++) {
            if (visitado[i] == 0)
                ciclo = dfs(i);
        }

        if (ciclo)
            printf("SIM\n");
        else
            printf("NAO\n");

        free(visitado);
        free(inicio);
        free(destino);
        free(prox);
    }

    return 0;
}
