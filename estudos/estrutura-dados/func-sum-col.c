#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int tam = 5; //gloabal var
int mat[5][5]; //global var
void printMat() {
    for (int i = 0; i < tam; i++)
    {
        for (int j = 0; j < tam; j++)
            printf("%2d ", mat[i][j]);
        printf("\n");
    }
}
int sumCol(int c) {
    int sum = 0;
    for(int i = 0; i < tam; i++)
        sum += mat[i][c];
    return sum;
}
int main (void) {
    srand(time(NULL));
    for (int i = 0; i < tam; i++)
        for (int j = 0; j < tam; j++)
            mat[i][j] = rand() % 10; // random numbers between 0 and 9
    printMat(mat);
    for(int i = 0; i < tam; i++)
        printf("A soma da coluna %d e: %d\n", i, sumCol(i));
    return 0;
}