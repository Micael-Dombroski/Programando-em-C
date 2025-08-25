#include <stdio.h>
#include <stdlib.h>
void printMatrix(int *pointer, int rows, int cols) {
    int rowCount = 1;
    for (int i = 0; i < (rows * cols); i++) {
        printf("|");
        printf(" %3d ", *(pointer + i));
        if(i != 0 && (double)cols/rowCount == (double)i + 1) {
            printf("|\n");
            rowCount++;
        }
    }
    printf("|\n");
}
void matrixMult(int matMult[][3], int mat1[][2], int mat2[][3]) {
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 2; k++)
                matMult[i][j] += mat1[i][k] * mat2[k][j];
}
int main(void) {
    int mat1[2][2], mat2[2][3], matMult[2][3] = {0}, ret = 0;
    char c;
    do {
        printf("Insert 4 integers: ");
        ret = scanf("%d%d%d%d", &mat1[0][0], &mat1[0][1], &mat1[1][0], &mat1[1][1]);
        while((c = getchar()) != '\n');
    } while(ret != 4);
    do {
        printf("Insert more 6 integers: ");
        ret = scanf("%d%d%d%d%d%d", &mat2[0][0], &mat2[0][1], &mat2[0][2], &mat2[1][0], &mat2[1][1], &mat2[1][2]);
        while((c = getchar()) != '\n');
    } while(ret != 6);
    printf("\nMatrix 1\n");
    printMatrix(&mat1[0][0], 2, 2);
    printf("\nMatrix 2\n");
    printMatrix(&mat2[0][0], 2, 3);
    printf("\nMatrix Mult\n");
    matrixMult(matMult, mat1, mat2);
    printMatrix(&matMult[0][0], 2, 3);
    printf("\n");
    return 0;
}