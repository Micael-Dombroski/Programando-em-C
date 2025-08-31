#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void) {
    int **mat, row = 5, col = 5;
    mat = calloc(4, sizeof(int*));
    for (int i = 0; i < row; i++)
        mat[i] = calloc(col, sizeof(int));
    srand(time(NULL));
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            //mat[i][j] = rand() % 20;
            *(*(mat + i) + j) = rand() % 20;//pointer arithmetic
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
            //printf("%2d ", mat[i][j]);
            printf("%2d ", *(*(mat + i) + j));
            //using pointer arithmetic to access the current element in the matrix
        printf("\n");
    }
    for (int i = 0; i < row; i++)
        free(mat[i]);
    free(mat);
    mat = NULL;
    
    return 0;
}