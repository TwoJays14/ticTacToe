#include <stdio.h>
#include <ctype.h>

/*
 * Game Rules:
 * 3 x 3 game board
 * One player is X , The other player is O
 * Players take turns and place their respective letters on any available spaces on the board
 * A player wins when they have 3 connecting X's or O's. This can be horizontally, vertically or diagonally
 */

// TODO: print board
// TODO: player selection

void printBoard();
void takeTurn(int *ptrPlayerOneTurnTotal, int *ptrPlayerTwoTurnTotal, char player1, char player2);
void makeMove( int playerMoveChoice, char symbol);
char checkWinCondition(char board[3][3]);

struct Players {
    char player1;
    char player2;
    int playerOneTurnTotal;
    int playerTwoTurnTotal;
};

char board[3][3] = {
    {' ' , ' ' , ' '},
    {' ' , ' ' , ' '},
    {' ' , ' ' , ' '}
};



int main(void)
{
    struct Players players;

    players.playerOneTurnTotal = 0;
    players.playerTwoTurnTotal = 0;

    int *ptrPlayerOneTurnTotal = &players.playerOneTurnTotal;
    int *ptrPlayerTwoTurnTotal = &players.playerTwoTurnTotal;


    char playerSelection;
    char *ptrPlayerSelection = &playerSelection;

    printf("Welcome to Tic Tac Toe, do you want to be X's or O's? Make you selection by typing 'X' or 'O'...\n");
    scanf("%c", ptrPlayerSelection);

    players.player1 = toupper(*ptrPlayerSelection);
    // printf("%c\n", players.player1);
    players.player2 = toupper(*ptrPlayerSelection) == 'X' ? 'O' : 'X';

    // printf("Player 1: %c\nPlayer 2: %c\n", players.player1, players.player2);

    for(int i = 0; i < 9; i++) {
    takeTurn(ptrPlayerOneTurnTotal, ptrPlayerTwoTurnTotal, players.player1, players.player2);
    printBoard();
    if (checkWinCondition(board) == 'X') {
        printf("Congratulations player 1! You win");
        break;
    }

    if (checkWinCondition(board) == 'O') {
        printf("Congratulations player 2! You win");
        break;
    }

    if (i == 8 && checkWinCondition(board) == 'D') {
        printf("Its a draw!");
    }

    }


    return 0;
}

void printBoard() {

    printf("                        |            |\n");
    printf("                  %c       |     %c      |       %c\n", board[0][0], board[0][1], board[0][2]);
    printf("                          |            |\n");
    printf("             _____________|____________|_______________\n");
    printf("                          |            |\n");
    printf("                  %c       |     %c      |       %c\n", board[1][0], board[1][1], board[1][2]);
    printf("                          |            |\n");
    printf("             _____________|____________|_______________\n");
    printf("                          |            |\n");
    printf("                  %c       |     %c      |       %c\n", board[2][0], board[2][1], board[2][2]);
    printf("                          |            |\n");
}
void takeTurn(int *ptrPlayerOneTurnTotal, int *ptrPlayerTwoTurnTotal, char player1, char player2) {
    int playerMoveChoice;


    if (*ptrPlayerOneTurnTotal == *ptrPlayerTwoTurnTotal) {
        printf("Player 1: Please select where you want to place your '%c'\n", player1);
        scanf("%d", &playerMoveChoice);
        makeMove(playerMoveChoice, player1);
        (*ptrPlayerOneTurnTotal)++;
    } else {
        printf("Player 2: Please select where you want to place your '%c'\n", player2);
        scanf("%d", &playerMoveChoice);
        makeMove(playerMoveChoice, player2);
        (*ptrPlayerTwoTurnTotal)++;
    }

}

void makeMove(int playerMoveChoice, char symbol) {
    int rowPosition = (playerMoveChoice - 1) / 3;
    int colPosition = (playerMoveChoice - 1) % 3;

    printf("%d %d", rowPosition, colPosition);

    if(board[rowPosition][colPosition] == ' ') {
        board[rowPosition][colPosition] = symbol;
    }
}

char checkWinCondition(char board[3][3]) {
    int i = 0;
    int j = 0;
    char winner = 'D';

    if(board[i][j] == 'X' && board[i][j+1] == 'X' && board[i][j+2] == 'X') {
        winner = 'X';
    } else if (board[i+1][j] == 'X' && board[i+1][j+1] == 'X' && board[i+1][j+2] == 'X') {
        winner = 'X';
    } else if (board[i+2][j] == 'X' && board[i+2][j+1] == 'X' && board[i+2][j+2] == 'X') {
        winner = 'X';
    } else if (board[i][j] == 'X' && board[i+1][j] == 'X' && board[i+2][j] == 'X') {
        winner = 'X';
    } else if (board[i][j+1] == 'X' && board[i+1][j+1] == 'X' && board[i+2][j+1] == 'X') {
        winner = 'X';
    } else if (board[i][j+2] == 'X' && board[i+1][j+2] == 'X' && board[i+2][j+2] == 'X') {
        winner = 'X';
    } else if (board[i][j] == 'X' && board[i+1][j+1] == 'X' && board[i+2][j+2] == 'X') {
        winner = 'X';
    } else if (board[i][j+2] == 'X' && board[i+1][j+1] == 'X' && board[i+2][j] == 'X') {
        winner = 'X';
    }

    if(board[i][j] == 'O' && board[i][j+1] == 'O' && board[i][j+2] == 'O') {
        winner = 'O';
    } else if (board[i+1][j] == 'O' && board[i+1][j+1] == 'O' && board[i+1][j+2] == 'O') {
        winner = 'O';
    } else if (board[i+2][j] == 'O' && board[i+2][j+1] == 'O' && board[i+2][j+2] == 'O') {
        winner = 'O';
    } else if (board[i][j] == 'O' && board[i+1][j] == 'O' && board[i+2][j] == 'O') {
        winner = 'O';
    } else if (board[i][j+1] == 'O' && board[i+1][j+1] == 'O' && board[i+2][j+1] == 'O') {
        winner = 'O';
    } else if (board[i][j+2] == 'O' && board[i+1][j+2] == 'O' && board[i+2][j+2] == 'O') {
        winner = 'O';
    } else if (board[i][j] == 'O' && board[i+1][j+1] == 'O' && board[i+2][j+2] == 'O') {
        winner = 'O';
    } else if (board[i][j+2] == 'O' && board[i+1][j+1] == 'O' && board[i+2][j] == 'O') {
        winner = 'O';
    }


    return winner;
}


