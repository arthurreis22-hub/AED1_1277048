/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : <<<Arthur Reis Martins>>>
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/<<1080>>
Data        : 21/09/2026
Objetivo    : Ler cem números e devolver o maior e sua posição.
Dificuldade : <<<Não houve dificuldade>>>
Uso de IA   : <<<Não foi utilizado>>>
-------------------------------------------------------------------------- */

#include <stdio.h>
 
int main() {
 
 int num, maior = 1, pos;
 int i;
 
 for(i=0; i<100; i++) {
     
     scanf("%d", &num);
     
     if (num > maior) {
         maior = num;
         pos = i + 1;
     }
 }
 
    printf("%d\n%d\n", maior, pos);
    
    return 0;
}
