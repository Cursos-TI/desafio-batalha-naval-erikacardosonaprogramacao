#include <stdio.h>
#include <string.h>
#define TAMANHO 10
#define NAVIO 3

// Declaração dos protótipos das funções
int inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]);
int exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]);
int aplicarHabilidade(int tabuleiro[TAMANHO][TAMANHO], int habilidade[5][5], int origemX, int origemY);

// Matriz Cone (5x5)
int cone[5][5] = {
    {0, 0, 1, 0, 0},
    {0, 1, 1, 1, 0},
    {1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}
};

// Matriz Cruz (5x5)
int cruz[5][5] = {
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0},
    {1, 1, 1, 1, 1},
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0}
};

// Matriz Octaedro (5x5)
int octaedro[5][5] = {
    {0, 0, 1, 0, 0},
    {0, 1, 1, 1, 0},
    {1, 1, 1, 1, 1},
    {0, 1, 1, 1, 0},
    {0, 0, 1, 0, 0}
};

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    inicializarTabuleiro(tabuleiro);
    
    printf("Tabuleiro inicial:\n");
    exibirTabuleiro(tabuleiro);
    
    // Aplicando habilidades
    aplicarHabilidade(tabuleiro, cone, 4, 4);
    printf("\nTabuleiro com habilidade Cone:\n");
    exibirTabuleiro(tabuleiro);
    
    inicializarTabuleiro(tabuleiro);
    aplicarHabilidade(tabuleiro, cruz, 4, 4);
    printf("\nTabuleiro com habilidade Cruz:\n");
    exibirTabuleiro(tabuleiro);
    
    inicializarTabuleiro(tabuleiro);
    aplicarHabilidade(tabuleiro, octaedro, 4, 4);
    printf("\nTabuleiro com habilidade Octaedro:\n");
    exibirTabuleiro(tabuleiro);
    
    return 0;
}

// Função para inicializar o tabuleiro com água (0) e um navio (3) em uma posição fixa
int inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
    tabuleiro[4][4] = 3; // Exemplo de navio
    return 0;
}

// Função para exibir o tabuleiro
int exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    return 0;
}

// Função para aplicar uma matriz de habilidade ao tabuleiro
int aplicarHabilidade(int tabuleiro[TAMANHO][TAMANHO], int habilidade[5][5], int origemX, int origemY) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int x = origemX + i - 2;
            int y = origemY + j - 2;
            if (x >= 0 && x < TAMANHO && y >= 0 && y < TAMANHO && habilidade[i][j] == 1) {
                tabuleiro[x][y] = 5;
            }
        }
    }
    return 0;
}
