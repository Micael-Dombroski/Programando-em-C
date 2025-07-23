#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void) {
    int linhas =7,colunas = 3;
    int mat[linhas][colunas], trans[colunas][linhas];
    srand(time(NULL));
    for(int i= 0; i < linhas; i++) {
        for(int j = 0; j < colunas; j++) {
            mat[i][j] = rand() % 10;//num de 0 a 9
            trans[j][i] = mat[i][j];
        }
    }
    printf("Matriz %dx%d: \n", linhas, colunas);
    for(int i= 0; i < linhas; i++) {
        for(int j = 0; j < colunas; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\nTransposta da Matrz %dx%d: \n", linhas, colunas);
    for(int i = 0; i < colunas; i++) {
        for(int j= 0; j < linhas; j++) {
            printf("%d ", trans[i][j]);
        }
        printf("\n");
    }
    return 0;
}