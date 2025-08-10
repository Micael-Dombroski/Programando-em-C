#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
typedef struct {
    int bombsInNeighborhood;
    int isABomb;
    int isOpen;
} Position;

typedef struct {
    Position field[10][10];
} Minefield;
void incrementBombNeighborPos(Minefield *minefield, int r, int c) {
    if (r > 0) {
        (*minefield).field[r-1][c].bombsInNeighborhood++;//left
        if(c > 0)
            (*minefield).field[r-1][c-1].bombsInNeighborhood++;//left-bottom
        if( c < 9)
            (*minefield).field[r-1][c+1].bombsInNeighborhood++;//left-top
    }
    if (r < 9) {
        (*minefield).field[r+1][c].bombsInNeighborhood++;//right
        if(c > 0)
            (*minefield).field[r+1][c-1].bombsInNeighborhood++;//right-bottom
        if( c < 9)
            (*minefield).field[r+1][c+1].bombsInNeighborhood++;//right-top
    }
    if(c > 0)
        (*minefield).field[r][c-1].bombsInNeighborhood++;///bottom
    if(c < 9)
        (*minefield).field[r][c+1].bombsInNeighborhood++;//top
}
Minefield setGame(int bombsQuantitys) {
    srand(time(NULL));
    Minefield minefield;
    memset(&minefield, 0, sizeof(Minefield));
    //sets all Positions in field to 0
    int bombsPos[bombsQuantitys], count = 0;
    do {
        bombsPos[count] = rand() % 100;//num de 0 a 99
        for(int i= 0; i < count; i++) {
            if(bombsPos[count] == bombsPos[i]) {
                count --;
                break;
            }
        }
        count ++;
    } while (count < bombsQuantitys);
    for (int i = 0; i < bombsQuantitys; i++)
    {
        int bombCol = bombsPos[i] % 10;
        if(bombsPos[i] < 10) {
            minefield.field[0][bombCol].isABomb = 1;
            incrementBombNeighborPos(&minefield, 0, bombCol);
        } else if(bombsPos[i] < 20) {
            minefield.field[1][bombCol].isABomb = 1;
            incrementBombNeighborPos(&minefield, 1, bombCol);
        } else if (bombsPos[i] < 30) {
            minefield.field[2][bombCol].isABomb = 1;
            incrementBombNeighborPos(&minefield, 2, bombCol);
        } else if (bombsPos[i] < 40) {
            minefield.field[3][bombCol].isABomb = 1;
            incrementBombNeighborPos(&minefield, 3, bombCol);
        } else if (bombsPos[i] < 50) {
            minefield.field[4][bombCol].isABomb = 1;
            incrementBombNeighborPos(&minefield, 4, bombCol);
        } else if (bombsPos[i] < 60) {
            minefield.field[5][bombCol].isABomb = 1;
            incrementBombNeighborPos(&minefield, 5, bombCol);
        } else if (bombsPos[i] < 70) {
            minefield.field[6][bombCol].isABomb = 1;
            incrementBombNeighborPos(&minefield, 6, bombCol);
        } else if (bombsPos[i] < 80) {
            minefield.field[7][bombCol].isABomb = 1;
            incrementBombNeighborPos(&minefield, 7, bombCol);
        } else if (bombsPos[i] < 90) {
            minefield.field[8][bombCol].isABomb = 1;
            incrementBombNeighborPos(&minefield, 8, bombCol);
        } else  {
            minefield.field[9][bombCol].isABomb = 1;
            incrementBombNeighborPos(&minefield, 9, bombCol);
        }
    }
    return minefield;
}
void printMineField(Minefield *minefield){
    printf("    0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 \n");
    printf("-------------------------------------------\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d |", i);
        for (int j = 0; j < 10; j++)
        {
            if((*minefield).field[i][j].isOpen)
                printf(" %d |", (*minefield).field[i][j].bombsInNeighborhood);
            else
                printf("   |");
        }
        printf("\n");
    }
    printf("-------------------------------------------\n");
}
void openPositions(Minefield *minifield, int r, int c) {
    if(r > 9 || r < 0 || c > 9 || c < 0)
        return;
    if((*minifield).field[r][c].isOpen)
        return;//return if the position it's already open
    (*minifield).field[r][c].isOpen = 1;//open the position
    if((*minifield).field[r][c].bombsInNeighborhood != 0)
        return;
    openPositions(minifield, r-1, c);//check if the position on the left can be opened
    openPositions(minifield, r+1, c);//check if the position on the right can be opened
    openPositions(minifield, r, c-1);//check if the position on the top can be opened
    openPositions(minifield, r, c+1);//check if the position on the bottom can be opened
}
int positionCanBeOpen(Minefield *minifield, int r, int c) {
    if(r > 9 || r < 0 || c > 9 || c < 0) {
        printf("The coordinates are out of range\n");
        return 0;
    } else if((*minifield).field[r][c].isOpen) {
        printf("The position is already open\n");
        return 0;
    } else if((*minifield).field[r][c].isABomb)//verifying if the position is a bomb
        return -1;
    openPositions(minifield, r, c);
    return 1;
}
int winGame(Minefield *minefield, int totSafePos) {
    int count = 0;
    for(int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            if(minefield->field[i][j].isOpen)
                count++;
    if(count == totSafePos)
        return 1;
    return 0;
}
void showBombs(Minefield *minefield) {
    printf("    0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 \n");
    printf("-------------------------------------------\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d |", i);
        for (int j = 0; j < 10; j++)
        {
            if((*minefield).field[i][j].isOpen)
                printf(" %d |", (*minefield).field[i][j].bombsInNeighborhood);
            else if((*minefield).field[i][j].isABomb)
                printf(" X |");
            else
                printf("   |");
        }
        printf("\n");
    }
    printf("-------------------------------------------\n");
}
int main(void) {
    int bombs, ret = 0;
    char ch;
    do {
        printf("Enter the number of bombs for the Minefield game: (0 to 99)\n");
        ret = scanf("%d", &bombs);
        while((ch = getchar()) != '\n');
    } while(ret != 1 || (bombs < 1 || bombs > 99));
    Minefield game = setGame(bombs);
    int safePositionsQtty = 100 - bombs;
    printMineField(&game);
    while(1 == 1) {
        int r = 0, c = 0, result;
        do {
            printf("Enter the coordinates: (e.g,: 1 1)\n");
            ret = scanf("%d%d", &r, &c);
            while((ch = getchar()) != '\n');
        } while(ret != 2);
        result = positionCanBeOpen(&game, r, c);
        if(result == 0) {
            continue;
        } else if(result == -1) {
            printf("\n\nUh oh! You find a bomb!\n\n");
            showBombs(&game);
            break;
        }
        printMineField(&game);
        if(winGame(&game, safePositionsQtty)) {
            printf("\n\nCongratulations! You won the game!\n\n");
            printMineField(&game);
            break;
        }
    }
    printf("\nPress ENTER to exit\n");
    while ((ch = getchar()) != '\n');
    return 0;
}