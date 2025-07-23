#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void) {
    int mat[5][10], sumCol[5] = {0}, sumRow[10] = {0}, tot=0;
    srand(time(NULL));
    for(int i= 0; i < 5; i++) {
        for(int j = 0; j < 10; j++) {
            mat[i][j] = rand() % 10;//num between 0 and 9 - num entre 0 e 9
            sumCol[i] += mat[i][j];
            sumRow[j] += mat[i][j];
            tot += mat[i][j];
        }
    }
    printf("       Collumn0  Collumn1  Collumn2  Collumn3  Collumn4  SumRow\n");
    for(int j = 0; j < 10; j++) {
        printf("Row%2d ", j);
        for(int i = 0; i < 5; i ++) {
            printf(" %8d ", mat[i][j]);
            if(i == 4) printf(" %6d", sumRow[j]);
        }
        printf("\n");
    }
    printf("SumCol");
    for(int i = 0; i < 5; i++)
        printf(" %8d ", sumCol[i]);
    printf(" %6d\n", tot);
    return 0;
}