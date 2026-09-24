/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : <<<Arthur Reis Martins>>>
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/<<1080>>
Data        : 22/09/2026
Objetivo    : Ler uma quantidade n de matrizes 9x9 e verificar se elas sao ou não solucao de Sudoku.
Dificuldade : <<<Vetor verifica[10] foi oq tive mais dificuldade, assim como a verificacao das matrizes 3x3>>>
Uso de IA   : <<<Compreender melhor o funcionamento do vetor verifica e como realizar a verificacao das matrizes 3x3 sem ter que fazer varios for para cada>>>
-------------------------------------------------------------------------- */

#include <stdio.h>

int main(){
	
	int Matriz[9][9], Sudoku, verifica[10], num;
	int n, instancia, i, j, k;
	int linha_3x3, coluna_3x3;
	
	scanf("%d", &n);
	
	for (instancia=1; instancia <= n; instancia++){
		for (i=0; i<9; i++){
			for (j=0; j<9; j++){
				
				scanf("%d", &Matriz[i][j]);
			}
		}
		
		Sudoku = 1;
		
		for (i=0; i<9; i++){
			for (j=0; j<10; j++){
				verifica[j] = 0;
			}
			
			for (j=0; j<9; j++){
				
				num = Matriz[i][j];
				
				if (verifica[num] == 1){
					Sudoku = 0;
				}
				
				verifica[num] = 1;
			}
		}
			
		for (j=0; j<9; j++){
			for (i=0; i<10; i++){
				verifica[i] = 0;
			}
				
			for (i=0; i<9; i++){
					
				num = Matriz[i][j];
				
				if(verifica[num] == 1){
					Sudoku =0;
				}
				
				verifica[num] = 1;
			}
		}
		
		for (linha_3x3 = 0; linha_3x3 < 9; linha_3x3 = linha_3x3 + 3) {
            for (coluna_3x3 = 0; coluna_3x3 < 9; coluna_3x3 = coluna_3x3 + 3) {
                for (i = 0; i < 10; i++) {
                    verifica[i] = 0;
                }
                for (i = linha_3x3; i < linha_3x3 + 3; i++) {
                    for (j = coluna_3x3; j < coluna_3x3 + 3; j++) {

                        num = Matriz[i][j];

                        if (verifica[num] == 1) {
                            Sudoku = 0;
                        }

                        verifica[num] = 1;
                    }
                }
            }
        }
		
		if (Sudoku == 1){
			printf("Instancia %d\nSIM\n\n", instancia);
		}
		else{
			printf("Instancia %d\nNAO\n\n", instancia);
		}
		
	}
	
	
	return 0;
}
