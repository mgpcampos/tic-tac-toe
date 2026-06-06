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
    printf("Enter row (0-2): ");
    scanf("%d", &row);
    printf("Enter column (0-2): ");
    scanf("%d", &col);

    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
        board[row][col] = symbol;
        return 1; // Move successful
    } else {
        printf("Invalid move. Try again.\n");
        return 0; // Move failed
    }
}

int main() {

}