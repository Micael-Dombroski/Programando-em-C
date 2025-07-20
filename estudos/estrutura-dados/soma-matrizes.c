#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void) {
    int tam = 5;
    int mat1[tam][tam], mat2[tam][tam], mat3[tam][tam];
    srand(time(NULL));
    for(int i = 0; i < tam; i++) {
        for(int j = 0; j < tam; j++) {
            mat1[i][j] = rand() % 10;//num entre 0 e 9
            mat2[i][j] = rand() % 10;//num entre 0 e 9
            mat3[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    printf("\nMatriz 1: \n");
    for(int i = 0; i < tam; i++) {
        for(int j = 0; j < tam; j++) {
            printf("%d ", mat1[i][j]);
        }
        printf("\n");
    }
    printf("\nMatriz 2: \n");
    for(int i = 0; i < tam; i++) {
        for(int j = 0; j < tam; j++) {
            printf("%d ", mat2[i][j]);
        }
        printf("\n");
    }
    printf("\nSoma das Matrizes 1 e 2: \n");
    for(int i = 0; i < tam; i++) {
        for(int j = 0; j < tam; j++) {
            printf("%4d ", mat3[i][j]);
        }
        printf("\n");
    }
    return 0;
}