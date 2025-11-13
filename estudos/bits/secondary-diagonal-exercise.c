#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int main(void) {
    int i, j, mat[SIZE][SIZE];
    srand(time(NULL));
    for(i = 0; i < SIZE; i++)
        for(j = 0; j < SIZE; j++)
            mat[i][j] = rand() % 100;

    printf("\n\tMatrix %dx%d\n", SIZE, SIZE);
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++)
            printf("%2d ",mat[i][j]);
        printf("\n");
    }
    printf("\n\tValues below the secondary diagonal\n");
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            if(j >= SIZE - i) {
                printf("%02d ",mat[i][j]);
            } else {
                printf("   ");
            }
        }
        printf("\n");
    }
    return EXIT_SUCCESS;
}