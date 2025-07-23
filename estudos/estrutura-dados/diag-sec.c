#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void) {
    int tam = 7;
    int mat[tam][tam], vet[tam];
    srand(time(NULL));
    for(int i= 0; i < tam; i++) {
        for(int j = 0; j < tam; j++) {
            mat[i][j] = rand() % 10;//num de 0 a 9
            if(j == tam-1-i) vet[i] = mat[i][j];
        }
    }
    printf("Matriz %dx%d: \n", tam, tam);
    for(int i= 0; i < tam; i++) {
        for(int j = 0; j < tam; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\nDiagonal secundaria: \n");
    for(int i= 0; i < tam; i++) {
        for(int j = 0; j < tam; j++) {
            if(j == tam-1-i) {
                printf("%d ", vet[i]);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
    return 0;
}