#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int tam = 5; //global var
void printMat(int m[][tam]) {
    for (int i = 0; i < tam; i++)
    {
        for (int j = 0; j < tam; j++)
            printf("%2d ", m[i][j]);
        printf("\n");
    }
}
int sumRow(int m[][tam], int r) {
    int sum = 0;
    for(int i = 0; i < tam; i++)
        sum += m[r][i];
    return sum;
}
int main (void) {
    int mat[tam][tam];
    srand(time(NULL));
    for (int i = 0; i < tam; i++)
        for (int j = 0; j < tam; j++)
            mat[i][j] = rand() % 10; // random numbers between 0 and 9
    printMat(mat);
    for(int i = 0; i < tam; i++)
        printf("A soma da linha %d e: %d\n", i, sumRow(mat, i));
    return 0;
}