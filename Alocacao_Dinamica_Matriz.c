#include <stdio.h>
#include <stdlib.h>

int main(void) {
	
	int linhas, colunas;
	
	printf("Digite o numero de linhas e colunas: ");
	
	if(scanf("%d %d", &linhas, &colunas) != 2 || linhas <= 0 || colunas <= 0) {
		printf("Numero de linhas ou colunas invalida(s))!\n");
		return 1;
	}
	
	int *matriz = malloc((size_t)linhas * colunas * sizeof(int));
	
	if (matriz == NULL) {
		printf("Erro na alocacao de memoria!\n");
		return 1;
	}
	
	int i, j;
	
	for (i=0; i<linhas; i++) {
		
		for (j=0; j<colunas; j++) {
			printf("Digite o elemento [%d] [%d]: ", i, j);
			
			if(scanf("%d", &matriz[i * colunas + j]) !=1) {
				printf("Entrada invalida!\n");
				free(matriz);
				return 1;
			}
		}
	}
	
	printf("\nMatriz original:\n");
	
	for (i=0; i<linhas; i++) {
		for (j=0; j<colunas; j++) {
			printf("%d ", matriz[i * colunas + j]);
		}
		printf("\n");
	}
	
	int novas_linhas, novas_colunas;
	
	printf("\nDigite o novo numero de linhas e colunas: ");
	
	if(scanf("%d %d", &novas_linhas, &novas_colunas) != 2 || novas_linhas <= 0 || novas_colunas <=0) {
		printf("Numero de novas linhas ou colunas invalida!");
		free(matriz);
		return 1;
	}
	
	int *nova_matriz = malloc((size_t)novas_linhas * novas_colunas * sizeof(int));
	
	if (nova_matriz == NULL) {
		printf("Erro na alocacao de memoria!");
		free(matriz);
		return 1;
	}
	
	// Essa parte eh necessaria justamente pq os novos elementos a serem preenchidos nao sao apenas os mais novo, mas por exemplo,
	// se aumentarmos o numero de colunas, sera necessario adicionar novos elementos em cada linha, alem das possiveis novas linhas
	// que tambem podem ter sido adicionadas.
	
	// Alem de que ele evita que os elementos sejam esticados, por exemplo, se eu tiver uma matriz 2x2 e depois pedir uma 1x4, ao inves
	// de ja me mandar uma matriz 1x4 com os mesmo valores da 2x2, so que esticados, ele fara o correto, que eh pedir os novos dois que
	// vao ficar nas posicoes [0][2] e [0][3].
	
	for (i = 0; i < linhas && i < novas_linhas; i++) {
		
		for (j = 0; j < colunas && j < novas_colunas; j++) {
			nova_matriz[i * novas_colunas + j] = matriz[i * colunas + j];
		}
	}
	
	for (i = 0; i < novas_linhas; i++) {
		for (j = 0; j < novas_colunas; j++) {
			
			// essa proxima parte serve justamente para ver se essa posicao eh nova ou nao, portanto se vai receber ou nao um valor ou ja tem um.
			
			if ( i >= linhas || j >= colunas) {
				printf("Digite o elemento [%d] [%d]: ", i, j);
				
				if (scanf("%d", &nova_matriz[i * novas_colunas + j]) != 1) {
					
					printf("Entrada invalida!\n");
					free(nova_matriz);
					free(matriz);
					return 1;
				}
			}
		}
	}
	
	printf("\nNova Matriz:\n");
	
	for(i = 0; i < novas_linhas; i++) {
		
		for(j = 0; j < novas_colunas; j++) {
			printf("%d ", nova_matriz[i * novas_colunas + j]);
		}
		printf("\n");
	}
	
	free(nova_matriz);
	free(matriz);
	
	return 0;
}
