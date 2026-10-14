/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : <<<Arthur Reis Martins>>>
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/<<1080>>
Data        : 21/09/2026
Objetivo    : Ler cem números e devolver o maior e sua posição. Utilizando alocacao dinamica de memoria com vetores
Dificuldade : <<<Entendimento inicial do malloc>>>
Uso de IA   : <<<Entender o malloc>>>
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	
	int n = 100, i;
	
	int *v = malloc((size_t)n * sizeof(int));
	
	for (i=0; i<n; i++) {
		scanf("%d", &v[i]);
	}
	
	int maior = v[0], posicao_maior;
	
	for (i=1; i<n; i++) {
		if(maior < v[i]) {
			maior = v[i];
			posicao_maior = i + 1;
		}
	}
	
	printf("%d\n%d\n", maior, posicao_maior);
	
	return 0;
}
