#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool posicao_valida(char tabuleiro[TAMANHO][TAMANHO], int celula) {
    if (celula < 1 || celula > 9) return false;
    else return true;
}

void ler_jogada(char tabuleiro[TAMANHO][TAMANHO], int *celula) {
    do {
        printf("Insira a célula almejada [1-9]: ");
        scanf("%d", celula);
    } while (!posicao_valida(tabuleiro, *celula));
}

bool verificar_vitoria(char tabuleiro[TAMANHO][TAMANHO], char simbolo) {
    // Laço responsável por varrer as linhas
    for (int i = 0; i < TAMANHO; i++) {
        if (tabuleiro[i][0] == simbolo &&
            tabuleiro[i][1] == simbolo &&
            tabuleiro[i][2] == simbolo)
            return true;
    }

    // Colunas
    for (int j = 0; j < TAMANHO; j++) {
        if (tabuleiro[0][j] == simbolo &&
            tabuleiro[1][j] == simbolo &&
            tabuleiro[2][j] == simbolo)
            return true;
    }

    // Diagonal da esquerda para a direita
    if (tabuleiro[0][0] == simbolo &&
        tabuleiro[1][1] == simbolo &&
        tabuleiro[2][2] == simbolo)
        return true;

    // Diagonal da direita para a esquerda
    if (tabuleiro[0][2] == simbolo &&
        tabuleiro[1][1] == simbolo &&
        tabuleiro[2][0] == simbolo)
        return true;

    return false;
}

bool tabuleiro_cheio(char tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            if (tabuleiro[i][j] == CELULA_VAZIA) return false;
        }
    }
    return true;
}

char verificar_fim(char tabuleiro[TAMANHO][TAMANHO]) {
    if (verificar_vitoria(tabuleiro, 'X')) return 'X';
    if (verificar_vitoria(tabuleiro, 'O')) return 'O';
    if (tabuleiro_cheio(tabuleiro)) return 'E';
    return 0;
}



int main() {
    int modo;

    modo = exibir_menu();




    char tabuleiro[TAMANHO][TAMANHO] = {
        {'X', 'O', 'X'},
        {'O', 'X', 'O'},
        {'X', 'O', 'X'}
    };
    // inicializar_tabuleiro(tabuleiro);
    // exibir_tabuleiro(tabuleiro);
    return 0;
}
