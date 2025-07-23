#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void) {
    int tam = 10;
    int mat[tam][tam];
    srand(time(NULL));
    for(int i= 0; i < tam; i++) {
        for(int j = 0; j < tam; j++) {
            mat[i][j] = rand() % 10;//num de 0 a 9
        }
    }
    printf("Matriz %dx%d: \n", tam, tam);
    for(int i= 0; i < tam; i++) {
        for(int j = 0; j < tam; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\nElementos abaixo da Matriz Principal\n");
    for(int i= 0; i < tam; i++) {
        for(int j = 0; j < tam; j++) {
            if(i > j) {
                printf("%d ", mat[i][j]);
            } else printf("  ");
        }
        printf("\n");
    }
    return 0;
}