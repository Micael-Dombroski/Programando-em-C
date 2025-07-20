#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void) {
    int mat[5][5] = {0}, vet[5];
    srand(time(NULL));
    for(int i= 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            mat[i][j] = rand() % 10;//num de 0 a 9
            if(i == j) vet[i] = mat[i][j];
        }
    }
    printf("Matriz 5x5: \n");
    for(int i= 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\nDiagonal principal: \n");
    for(int i= 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
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