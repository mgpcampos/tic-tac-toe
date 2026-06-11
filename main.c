#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void exibir_instrucoes() {
    limpar_tela();
    exibir_titulo();
    printf("Para jogar, escolha uma posição digitando o número correspondente [1-9].\n"); 
    printf("\n");
    printf("%48s 1 | 2 | 3 \n", "");
    printf("%48s---+---+---\n", "");
    printf("%48s 4 | 5 | 6 \n", "");
    printf("%48s---+---+---\n", "");
    printf("%48s 7 | 8 | 9 \n", "");
    printf("\n");
    printf("Pressione Enter para continuar...");

    while (getchar() != '\n');
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

int exibir_primeiro_menu() {
    int opcao;
    limpar_tela();
    exibir_titulo();
    printf("\n");
    printf("1. Jogador vs Jogador\n");
    printf("2. Jogador vs Computador\n\n");
    printf("Insira uma opção: ");

    do {
        scanf("%d", &opcao);
    } while (opcao != 1 && opcao != 2);

    return opcao;
}

int exibir_segundo_menu() {
    int opcao;
    limpar_tela();
    exibir_titulo();
    printf("Nível de inteligência do computador:\n");
    printf("1. Básico (aleatório)\n");
    printf("2. Intermediário (ofensivo/defensivo)\n\n");
    printf("Insira uma opção: ");

    do {
        scanf("%d", &opcao);
    } while (opcao != 1 && opcao != 2);

    return opcao;
}

void converter_celula_para_coordenadas(int celula, int *linha, int *coluna) {
    int indice = celula - 1;
    *linha = indice / TAMANHO;
    *coluna = indice % TAMANHO;
}

bool posicao_valida(char tabuleiro[TAMANHO][TAMANHO], int celula) {
    int linha, coluna;

    if (celula < 1 || celula > 9) return false;

    converter_celula_para_coordenadas(celula, &linha, &coluna);

    return tabuleiro[linha][coluna] == CELULA_VAZIA;
}

void ler_jogada(char tabuleiro[TAMANHO][TAMANHO], int *celula) {
    do {
        printf("Insira a célula desejada [1-9]: ");
        scanf("%d", celula);
    } while (!posicao_valida(tabuleiro, *celula));
}

bool verificar_vitoria(char tabuleiro[TAMANHO][TAMANHO], char simbolo) {
    // Laço responsável por varrer as linhas
    for (int i = 0; i < TAMANHO; i++) {
        if (tabuleiro[i][0] == simbolo && tabuleiro[i][1] == simbolo &&
            tabuleiro[i][2] == simbolo)
            return true;
    }

    // Colunas
    for (int j = 0; j < TAMANHO; j++) {
        if (tabuleiro[0][j] == simbolo && tabuleiro[1][j] == simbolo &&
            tabuleiro[2][j] == simbolo)
            return true;
    }

    // Diagonal da esquerda para a direita
    if (tabuleiro[0][0] == simbolo && tabuleiro[1][1] == simbolo &&
        tabuleiro[2][2] == simbolo)
        return true;

    // Diagonal da direita para a esquerda
    if (tabuleiro[0][2] == simbolo && tabuleiro[1][1] == simbolo &&
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

/*
 * Nível básico: escolhe aleatoriamente uma célula livre entre 1 e 9
 * e marca a jogada no tabuleiro.
 */
void jogada_computador_basico(char tabuleiro[TAMANHO][TAMANHO], char simbolo) {
    int celula, linha, coluna;
    do {
        celula = rand() % (TAMANHO * TAMANHO) + 1;
    } while (!posicao_valida(tabuleiro, celula));

    converter_celula_para_coordenadas(celula, &linha, &coluna);
    tabuleiro[linha][coluna] = simbolo;
}

/*
 * Procura uma linha, coluna ou diagonal com duas peças de simbolo_busca
 * e uma casa vazia. Se encontrar, coloca simbolo_colocar na posição livre.
 * Retorna 1 se fizer a jogada, ou 0 se não houver oportunidade.
 */
int tentar_jogada_estrategica(char tabuleiro[TAMANHO][TAMANHO],
                              char simbolo_busca, char simbolo_colocar) {
    // Varredura nas linhas
    for (int i = 0; i < TAMANHO; i++) {
        int contagem = 0, col_vazia = -1;
        for (int j = 0; j < TAMANHO; j++) {
            if (tabuleiro[i][j] == simbolo_busca)
                contagem++;
            else if (tabuleiro[i][j] == CELULA_VAZIA)
                col_vazia = j;
        }
        if (contagem == 2 && col_vazia != -1) {
            tabuleiro[i][col_vazia] = simbolo_colocar;
            return 1;
        }
    }

    // Varredura nas colunas
    for (int j = 0; j < TAMANHO; j++) {
        int contagem = 0, lin_vazia = -1;
        for (int i = 0; i < TAMANHO; i++) {
            if (tabuleiro[i][j] == simbolo_busca)
                contagem++;
            else if (tabuleiro[i][j] == CELULA_VAZIA)
                lin_vazia = i;
        }
        if (contagem == 2 && lin_vazia != -1) {
            tabuleiro[lin_vazia][j] = simbolo_colocar;
            return 1;
        }
    }

    // Diagonal da esquerda para a direita
    {
        int contagem = 0, pos_vazia = -1;
        for (int i = 0; i < TAMANHO; i++) {
            if (tabuleiro[i][i] == simbolo_busca)
                contagem++;
            else if (tabuleiro[i][i] == CELULA_VAZIA)
                pos_vazia = i;
        }
        if (contagem == 2 && pos_vazia != -1) {
            tabuleiro[pos_vazia][pos_vazia] = simbolo_colocar;
            return 1;
        }
    }

    // Diagonal da direita para a esquerda
    {
        int contagem = 0, pos_vazia = -1;
        for (int i = 0; i < TAMANHO; i++) {
            int j = TAMANHO - 1 - i;
            if (tabuleiro[i][j] == simbolo_busca)
                contagem++;
            else if (tabuleiro[i][j] == CELULA_VAZIA)
                pos_vazia = i;
        }
        if (contagem == 2 && pos_vazia != -1) {
            int col = TAMANHO - 1 - pos_vazia;
            tabuleiro[pos_vazia][col] = simbolo_colocar;
            return 1;
        }
    }

    return 0;
}

/*
 * Nível intermediário: primeiro tenta vencer, depois bloquear, depois joga
 * aleatório.
 */
void jogada_computador_intermediario(char tabuleiro[TAMANHO][TAMANHO],
                                     char simbolo_computador,
                                     char simbolo_jogador) {
    // 1. Verifica se o computador pode vencer na próxima jogada
    if (tentar_jogada_estrategica(tabuleiro, simbolo_computador,
                                  simbolo_computador))
        return;

    // 2. Bloqueia o jogador se ele estiver prestes a ganhar
    if (tentar_jogada_estrategica(tabuleiro, simbolo_jogador,
                                  simbolo_computador))
        return;

    // 3. Alternativa: jogada aleatória
    jogada_computador_basico(tabuleiro, simbolo_computador);
}

int main() {
    srand(time(NULL));
    int modo;
    char tabuleiro[TAMANHO][TAMANHO];
    inicializar_tabuleiro(tabuleiro);

    exibir_instrucoes();

    modo = exibir_primeiro_menu();

    int nivel = 1;
    if (modo == 2) nivel = exibir_segundo_menu();

    char simbolos[2] = {'X', 'O'};
    int turno = 0;  // 0 = X, 1 = O
    char resultado;

    printf("X começa. Boa sorte!\n");

    while ((resultado = verificar_fim(tabuleiro)) == 0) {
        exibir_tabuleiro(tabuleiro);
        char simbolo_atual = simbolos[turno];

        if (modo == 2 && turno == 1) {
            // Vez do computador
            printf("Vez do computador (%c)...\n", simbolo_atual);
            if (nivel == 1)
                jogada_computador_basico(tabuleiro, simbolo_atual);
            else
                jogada_computador_intermediario(tabuleiro, simbolo_atual,
                                                simbolos[0]);
        } else {
            // Vez do humano
            printf("Vez do jogador %c:\n", simbolo_atual);
            int linha, coluna, celula;
            ler_jogada(tabuleiro, &celula);
            converter_celula_para_coordenadas(celula, &linha, &coluna);
            tabuleiro[linha][coluna] = simbolo_atual;
        }

        turno = 1 - turno;  // Alterna entre 0 e 1
    }

    exibir_tabuleiro(tabuleiro);

    if (resultado == 'E')
        printf("Empate! Nenhum vencedor desta vez.\n\n");
    else
        printf("Jogador %c venceu! Parabéns!\n\n", resultado);

    return 0;
}
