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

void inicializar_tabuleiro(char tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = CELULA_VAZIA;
        }
    }
}

void imprimir_tabuleiro(char tabuleiro[TAMANHO][TAMANHO]) {
    limpar_tela();
    printf("\n");
    printf("     ██╗ ██████╗  ██████╗  ██████╗     ██████╗  █████╗     ██╗   ██╗███████╗██╗     ██╗  ██╗ █████╗         \n");
    printf("     ██║██╔═══██╗██╔════╝ ██╔═══██╗    ██╔══██╗██╔══██╗    ██║   ██║██╔════╝██║     ██║  ██║██╔══██╗        \n");
    printf("     ██║██║   ██║██║  ███╗██║   ██║    ██║  ██║███████║    ██║   ██║█████╗  ██║     ███████║███████║        \n");
    printf("██   ██║██║   ██║██║   ██║██║   ██║    ██║  ██║██╔══██║    ╚██╗ ██╔╝██╔══╝  ██║     ██╔══██║██╔══██║        \n");
    printf("╚█████╔╝╚██████╔╝╚██████╔╝╚██████╔╝    ██████╔╝██║  ██║     ╚████╔╝ ███████╗███████╗██║  ██║██║  ██║        \n");
    printf(" ╚════╝  ╚═════╝  ╚═════╝  ╚═════╝     ╚═════╝ ╚═╝  ╚═╝      ╚═══╝  ╚══════╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝        \n");
    printf("\n");
    
    for (int i = 0; i < TAMANHO; i++) {
      printf(" %c | %c | %c\n", tabuleiro[i][0], tabuleiro[i][1],
             tabuleiro[i][2]);

      if (i < TAMANHO - 1) {
        printf("---+---+---\n");
      }
    }

    printf("\n");
}

int main() {
  char tabuleiro[TAMANHO][TAMANHO] = {
      {'X', 'O', 'X'},
      {'O', 'X', 'O'},
      {'X', 'O', 'X'}
  };
  // inicializar_tabuleiro(tabuleiro);
  imprimir_tabuleiro(tabuleiro);
  return 0;
}
