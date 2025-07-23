#include <stdio.h>
#include <stdlib.h>
#define row 3
#define col 3
void showGame(char game[row][col]) {
    for (int i = 0; i < 3; i++) {
        printf("|%c|%c|%c|\n", game[i][0],game[i][1], game[i][2]);
    }
}
int main(void) {
    char game[row][col] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    }, p1 = 'X', p2 = 'O', p = ' ', winner = ' ';
    for(int i = 0; i < 9; i++) {
        int validMove = 1, posR, posC;
        p = p == ' ' ? p1 : p == p1 ? p2 : p1;
        do {
            validMove = 1;
            printf("Jogado %c, informe a posicao desejada (linha e coluna, 0 a 2): \n", p);
            int ret = scanf("%d%d", &posR, &posC);
            if(posC > 2 || posC < 0 || posR > 2 || posR < 0)
                validMove = 0;
            else if(ret != 2 || game[posR][posC] != ' ')
                validMove = 0;
            
            if(!validMove) printf("Jogada invalida\n");
        } while (!validMove);
        game[posR][posC] = p;
        showGame(game);
        for(int j = 0; j < 3; j++) {
            if(game[j][0] != ' ' && game[j][0] == game[j][1] && game[j][1] == game[j][2]) {
                printf("aqui1\n");
                winner = p == 'X' ? '1' : '2';
                break;
            }
            if(game[0][j] != ' ' && game[0][j] == game[1][j] && game[1][j] == game[2][j]) {
                winner = p == 'X' ? '1' : '2';
                printf("aqui2\n");
                break;
            }
        }
        if(game[0][0] != ' ' && game[0][0] == game[1][1] && game[1][1] == game[2][2]) {
            winner = p == 'X' ? '1' : '2';
            printf("aqui3\n");
        } else if(game[0][2] != ' ' && game[0][2] == game[1][1] && game[1][1]  == game[2][0]) {
            winner = p == 'X' ? '1' : '2';
            printf("aqui4\n");
        }
        if(winner != ' ') break;
    }
    if(winner != ' ') {
        printf("\nJogador %c e o vencedor\n", winner);
    } else printf("\nDeu velha\n");
    showGame(game);
    return 0;
}