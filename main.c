#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 3
#define CELULA_VAZIA ' '

void limpar_tela() {
#ifdef _WIN32
    // Windows
    system("cls");
#else
    // macOS e Linux
    system("clear");
#endif
    fflush(stdout);
}

void inicializar_tabuleiro(char tabuleiro[3][3]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = CELULA_VAZIA;
        }
    }
}

void exibir_tabuleiro(char tabuleiro[3][3]) {

}

int main() { return 0; }