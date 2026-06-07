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

void exibir_titulo() {
    printf("\n");
    printf("     ██╗ ██████╗  ██████╗  ██████╗     ██████╗  █████╗     ██╗   ██╗███████╗██╗     ██╗  ██╗ █████╗         \n");
    printf("     ██║██╔═══██╗██╔════╝ ██╔═══██╗    ██╔══██╗██╔══██╗    ██║   ██║██╔════╝██║     ██║  ██║██╔══██╗        \n");
    printf("     ██║██║   ██║██║  ███╗██║   ██║    ██║  ██║███████║    ██║   ██║█████╗  ██║     ███████║███████║        \n");
    printf("██   ██║██║   ██║██║   ██║██║   ██║    ██║  ██║██╔══██║    ╚██╗ ██╔╝██╔══╝  ██║     ██╔══██║██╔══██║        \n");
    printf("╚█████╔╝╚██████╔╝╚██████╔╝╚██████╔╝    ██████╔╝██║  ██║     ╚████╔╝ ███████╗███████╗██║  ██║██║  ██║        \n");
    printf(" ╚════╝  ╚═════╝  ╚═════╝  ╚═════╝     ╚═════╝ ╚═╝  ╚═╝      ╚═══╝  ╚══════╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝        \n");
    printf("\n");
}

void inicializar_tabuleiro(char tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = CELULA_VAZIA;
        }
    }
}

void exibir_tabuleiro(char tabuleiro[TAMANHO][TAMANHO]) {
    limpar_tela();
    exibir_titulo();

    for (int i = 0; i < TAMANHO; i++) {
        printf(" %c | %c | %c\n", tabuleiro[i][0], tabuleiro[i][1],
            tabuleiro[i][2]);

        if (i < TAMANHO - 1) {
        printf("---+---+---\n");
      }
    }

    printf("\n");
}

int exibir_menu() {
    limpar_tela();
    exibir_titulo();
    int opcao;
    printf("1. Jogador vs Jogador\n");
    printf("2. Jogador vs Computador\n");
    printf("Escolha: ");

    do {
        scanf("%d", &opcao);
    } while (opcao != 1 && opcao != 2);

    return opcao;
}

int main() {
    int modo;

    modo = exibir_menu();
    printf("%d\n", modo);


    char tabuleiro[TAMANHO][TAMANHO] = {
        {'X', 'O', 'X'},
        {'O', 'X', 'O'},
        {'X', 'O', 'X'}
    };
    // inicializar_tabuleiro(tabuleiro);
    // exibir_tabuleiro(tabuleiro);
    return 0;
}
