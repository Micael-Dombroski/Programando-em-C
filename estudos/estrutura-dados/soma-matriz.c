#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void) {
    srand(time(NULL));
    int mat[5][7], soma = 0;
    for(int i = 0; i < 5; i ++) {
        for(int j = 0; j < 7; j++) {
            mat[i][j] = rand() % 100;
            soma += mat[i][j];
        }
    }
    printf("Valores da matriz\n");
    for(int i = 0; i < 5; i ++) {
        for(int j = 0; j < 7; j++)
            printf(" [%d][%d]=%3d -", i, j, mat[i][j]);
        printf("\n");
    }
    printf("\nA soma dos elementos da matriz e: %d\n", soma);
    return 0;
}