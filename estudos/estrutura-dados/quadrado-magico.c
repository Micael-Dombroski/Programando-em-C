#include <stdio.h>
#include <stdlib.h>
#define size 4 //constant
int main(void) {
    int mat[size][size] = {
        {16, 3, 2, 13},
        {5, 10, 11, 8},
        {9, 6, 7, 12},
        {4, 15, 14, 1}
    };

    int sumRow[size] = {0}, sumCol[4] = {0}, sumPrinD=0, sumSecD=0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            sumRow[i] += mat[i][j];
            sumCol[j] += mat[i][j];
            if(i == j) sumPrinD += mat[i][j];
            if(j == size-1-i) sumSecD += mat[i][j];
        }
    }
    printf("       ");
    for(int i = 0; i < size; i++)
        printf("C%d  ", i);
    printf("SumRow\n");
    for(int j = 0; j < size; j++) {
        printf("Row%2d ", j);
        for(int i = 0; i < size; i ++) {
            printf(" %2d ", mat[i][j]);
            if(i == size-1) printf(" %4d", sumRow[j]);
        }
        printf("\n");
    }
    printf("SumCol");
    for(int i = 0; i < size; i++)
        printf(" %2d ", sumCol[i]);
    printf("\n\nSum Principal Diagonal: %d\n", sumPrinD);
    printf("Sum Secondary Diagonal: %d\n", sumSecD);
    int magicCube = 1;
    for (int i = 0; i < size; i++)
    {
        if(sumCol[i] != sumPrinD) {
            magicCube = 0;
            break;
        } else if(sumRow[i] != sumPrinD) {
            magicCube = 0;
            break;
        }
    }
    if(magicCube != 0 && sumPrinD != sumSecD) magicCube = 0;
    
    printf("Magic Square: %s\n", magicCube == 1 ? "true" : "false");
    return 0;
}