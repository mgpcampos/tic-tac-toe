#include <stdio.h>

char board[3][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};

void printBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int makeMove(char board[3][3], char symbol) {
    int row, col;
    printf("Insira a linha (0-2): ");
    scanf("%d", &row);
    printf("Insira a coluna (0-2): ");
    scanf("%d", &col);

    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
        board[row][col] = symbol;
        return 1; // Jogada válida
    } else {
        printf("Jogada inválida. Tente novamente.\n");
        return 0; // Jogada inválida
    }
}

char checkWinner(char board[3][3]) {
    // Verifica as linhas
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return board[i][0];
        }
    }
    // Verifica as colunas
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ') {
            return board[0][j];
        }
    }
    // Verifica as diagonais
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return board[0][2];
    }
    return ' '; // Nenhum vencedor ainda
}

int boardFull(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return 0; // O tabuleiro ainda tem espaços vazios
            }
        }
    }
    return 1; // O tabuleiro está cheio
}

int main() {
    char currentPlayer = 'X';
    char winner = ' ';
    
    while (winner == ' ' && !boardFull(board)) {
        printBoard(board);
        printf("Jogador %c, é sua vez.\n", currentPlayer);
        
        if (makeMove(board, currentPlayer)) {
            winner = checkWinner(board);
            if (winner != ' ') {
                printf("Parabéns! Jogador %c venceu!\n", winner);
            } else if (boardFull(board)) {
                printf("Empate! O tabuleiro está cheio.\n");
            } else {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; // Alterna o jogador
            }
        }
    }
    
    printBoard(board);
    return 0;
}