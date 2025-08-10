#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct {
    int isABomb;
    int isOpen;
    int neighbors;
} Cell;
Cell game[10][10];
int size = 10;
void startGame() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            game[i][j].isABomb = 0;
            game[i][j].isOpen = 0;
            game[i][j].neighbors = 0;
        }
    }
}
void bombsGenerator(int quantity) {
    if(quantity >= size * size || quantity < 1) {
        printf("the number of bombs must be between 1 and %d\n", size-1);
        return;
    }
    srand(time(NULL));
    int row, col;
    for (int i = 0; i < quantity; i++) {
        row = rand() % size; //drawning the row number
        col = rand() % size; //drawning the collumn number
        if(!game[row][col].isABomb)//checking if the cell is already a bomb
            game[row][col].isABomb = 1;
        else
            i--;
    }
}
int coordinateIsValid(int row, int col) {
    if(row >= size || row < 0 || col >= size || col < 0)
        return 0;
    return 1;
}
//function that checks the number of bombs in the neighborhood
int bombsInTheNeighborhood(int row, int col) {
    int count = 0;
    //Is there a bomb on the right?
    if(coordinateIsValid(row, col + 1) && game[row][col + 1].isABomb)
        count++;
    //Is there a bomb on the left?
    if(coordinateIsValid(row, col - 1) && game[row][col - 1].isABomb)
        count++;
    //Is there a bomb on the top?
    if(coordinateIsValid(row + 1, col) && game[row + 1][col].isABomb)
        count++;
    //Is there a bomb on the bottom?
    if(coordinateIsValid(row - 1, col) && game[row - 1][col].isABomb)
        count++;
    return count;
}
void bombsCount() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            game[i][j].neighbors = bombsInTheNeighborhood(i, j);
    }
}
void print() {
    printf("\n\n\t    ");
    for (int i = 0; i < size; i++)
        printf(" %d  ", i);
    printf("\n\t   -----------------------------------------\n");
    for (int i = 0; i < size; i++) {
        printf("\t%d  |", i);
        for (int j = 0; j < size; j++) {
            if(game[i][j].isOpen) {
                if(game[i][j].isABomb)
                    printf(" * ");
                else
                    printf(" %d ", game[i][j].neighbors);
            }
            else
                printf("   ");
            printf("|");
        }
        printf("\n\t   -----------------------------------------\n");
    }
}
void openCell(int row, int col) {
    if(coordinateIsValid(row, col) && !game[row][col].isOpen)
        game[row][col].isOpen = 1;
    else
        return;
    if(game[row][col].neighbors == 0) {
        openCell(row, col+1); //neighbor on right
        openCell(row, col-1); //neighbor on left
        openCell(row+1, col); //neighbor up on screen
        openCell(row-1, col); //neighbor down on screen
    }
}
int itWon() {
    int closedSecureCells = 0;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if(!game[i][j].isABomb && !game[i][j].isOpen)
                closedSecureCells++;
    if(closedSecureCells == 0)
        return 1;
    return 0;
}
void play() {
    int row=0, col=0;
    do {
        print();
        do {
            printf("Enter the row and column coordinates: ");
            scanf("%d%d", &row, &col);
            if(!coordinateIsValid(row, col))
                printf("\nInvalid coordinates!\n");
            if(game[row][col].isOpen)
                printf("This cell is already open\n");
        } while(!coordinateIsValid(row, col) || game[row][col].isOpen);
        openCell(row, col);
    } while (!itWon() && !game[row][col].isABomb);
    if(game[row][col].isABomb)
        printf("\n\tWhat a shame! you lose :(\n\tYou found a bomb.\n");
    else
        printf("\n\tCongratulations! You win the game!\n");
    print();
}
int main(void) {
    int opt = -1;
    do {
        startGame();
        bombsGenerator(10);
        bombsCount();
        printf("\n\t\t\tMINE FIELD\n");
        play();
        printf("\n\tPress 1 + ENTER to play again: ");
        scanf("%d",&opt);
    } while(opt == 1);
    return 0;
}