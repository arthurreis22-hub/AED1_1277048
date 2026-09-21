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
