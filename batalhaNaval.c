#include <stdio.h>
#include <stdbool.h>

#define TAMANHO 10
#define TAMANHO_NAVIO 3

void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

bool posicionarNavio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int direcao) {
    if (direcao == 0) { // Horizontal
        if (coluna + TAMANHO_NAVIO > TAMANHO) return false;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha][coluna + i] != 0) return false;
        }
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha][coluna + i] = 3;
        }
    } else { // Vertical
        if (linha + TAMANHO_NAVIO > TAMANHO) return false;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha + i][coluna] != 0) return false;
        }
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha + i][coluna] = 3;
        }
    }
    return true;
}

void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    inicializarTabuleiro(tabuleiro);

    // Posição do primeiro navio (horizontal)
    if (!posicionarNavio(tabuleiro, 2, 3, 0)) {
        printf("Erro ao posicionar o primeiro navio.\n");
    }

    // Posição do segundo navio (vertical)
    if (!posicionarNavio(tabuleiro, 5, 5, 1)) {
        printf("Erro ao posicionar o segundo navio.\n");
    }

    exibirTabuleiro(tabuleiro);

    return 0;
}
