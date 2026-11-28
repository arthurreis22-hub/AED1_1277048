#include <stdio.h>

int busca_binaria(int casas[], int n, int valor) {
    int inicio = 0;
    int fim = n - 1;
    int meio;

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;

        if (casas[meio] == valor) {
            return meio;
        }
        else if (casas[meio] < valor) {
            inicio = meio + 1;
        }
        else {
            fim = meio - 1;
        }
    }

    return -1;
}

int main() {
    int n, m, i;
    int casas[45000];
    int atual, destino;
    int tempo = 0;

    scanf("%d %d", &n, &m);

    for (i = 0; i < n; i++) {
        scanf("%d", &casas[i]);
    }

    atual = 0;

    for (i = 0; i < m; i++) {
        scanf("%d", &destino);

        destino = busca_binaria(casas, n, destino);

        if (destino > atual) {
            tempo += destino - atual;
        }
        else {
            tempo += atual - destino;
        }

        atual = destino;
    }

    printf("%d\n", tempo);

    return 0;
}
