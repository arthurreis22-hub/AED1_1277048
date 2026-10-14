#include <stdio.h>
#include <stdlib.h>

int main(void) {
	
	int n;

	printf("Digite o numero de elementos do vetor: ");


	// esse !=1 esta ai justamente pq quando o scanf le um inteiro, ele devolve 1, e se ele nao ler um inteiro, devolve 0 //
	if(scanf("%d", &n) != 1 || n<=0) {
		printf("Tamanho invalido!\n");
		
		return 1;
	}
	

	int *v = malloc((size_t)n * sizeof(int));
	
	if (v == NULL) {
		
		printf("Erro na alocacao de memoria!\n");
		
		return 1;	
	}
	
	int i;
	
	for (i=0; i<n; i++) {
		
		printf("Digite o elemento %d: ", i);
	
		if(scanf("%d", &v[i]) != 1) {
			printf("Entrada invalida!\n");
			
			free(v);
			
			return 1;
		}
	}
	
	printf("\nO vetor eh: ");
	
	for (i=0; i<n; i++){
		
		printf("%d ", v[i]);
	}
	
	printf("\n\nDigite o novo numero de elementos do vetor: ");
	
	int m;
	
	if (scanf("%d", &m) !=1 || m<=0) {
		printf("Tamanho invalido!\n");
		
		free(v);
		
		return 1;
	}
	
	int *temp = realloc(v, (size_t)m * sizeof(int));
	
	if (temp == NULL) {
		printf("Erro na realocacao de memoria!\n");
		
		free(v);
		
		return 1;
	}
	
	v = temp;
	
	if (m <= n) {
		
		printf("\nO novo vetor eh: ");
		
		for (i=0; i<m; i++) {
			printf("%d ", v[i]);
		}
		
		free(v);
		
		return 0;
	}
	
	for (i = n; i<m; i++) {
		
		printf("Digite o elemento %d: ", i);
		
		if(scanf("%d", &v[i]) != 1) {
			printf("Entrada invalida!\n");
			
			free(v);
			
			return 1;		
		}
	}
	
	printf("\nO novo vetor eh: ");
	
	for (i = 0; i<m; i++) {
		
		printf("%d ", v[i]);
	}
	
	free(v);
	
	return 0;
}
