#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void) {
    int tam = 5;
    int mat[tam][tam], vet[tam];
    srand(time(NULL));
    for(int i= 0; i < tam; i++) {
        for(int j = 0; j < tam; j++) {
            mat[i][j] = rand() % 10;//num de 0 a 9
            if(i == j) vet[i] = mat[i][j];
        }
    }
    printf("Matriz %dx%d: \n", tam, tam);
    for(int i= 0; i < tam; i++) {
        for(int j = 0; j < tam; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\nDiagonal principal: \n");
    for(int i= 0; i < tam; i++) {
        for(int j = 0; j < tam; j++) {
            if(i == j) {
                printf("%d ", vet[i]);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
    return 0;
}