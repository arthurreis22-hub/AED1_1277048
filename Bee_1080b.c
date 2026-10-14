#include <stdio.h>
#include <stdlib.h>

int main(void) {
	
	int n = 5, i;
	
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
