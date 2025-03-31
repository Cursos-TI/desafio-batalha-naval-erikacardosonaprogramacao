#include <stdio.h>
#include <string.h>
#define TAMANHO 10
#define NAVIO 3

void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    int i = 0, j;
    while (i < TAMANHO) {
        j = 0;
        while (j < TAMANHO) {
            tabuleiro[i][j] = 0;
            j++;
        }
        i++;
    }
}

void posicionarNavio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int horizontal) {
    int i = 0;
    while (i < NAVIO) {
        if (horizontal) {
            tabuleiro[linha][coluna + i] = NAVIO;
        } else {
            tabuleiro[linha + i][coluna] = NAVIO;
        }
        i++;
    }
}

void imprimirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    int i = 0, j;
    while (i < TAMANHO) {
        j = 0;
        while (j < TAMANHO) {
            printf("%d ", tabuleiro[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    char resposta[10];
    int linhaNavio1 = 2, colunaNavio1 = 3;
    int linhaNavio2 = 5, colunaNavio2 = 6;
    
    inicializarTabuleiro(tabuleiro);
    posicionarNavio(tabuleiro, linhaNavio1, colunaNavio1, 1);
    posicionarNavio(tabuleiro, linhaNavio2, colunaNavio2, 0);
    
    while (1) {
        imprimirTabuleiro(tabuleiro);
        printf("\nDigite 'sim' para sair ou qualquer tecla para continuar: ");
        scanf("%s", resposta);
        if (strcmp(resposta, "sim") == 0) {
            printf("\nSaindo do programa...\n");
            break;
        }
    }
    
    return 0;
}
