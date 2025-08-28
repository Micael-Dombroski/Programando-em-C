#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void) {
    int **mat;
    //the matrix is a pointer to a pointer, create a 2d dynamic array
    mat = calloc(4, sizeof(int*));
    //allocate memory for 4 pointers to int(4 rows)
    if(mat) {
        for (int i = 0; i < 4; i++) {
            mat[i] = calloc(3, sizeof(int));
            //allocate memory for 3 int in each row(3 columns)
            if(mat[i] == NULL) {
                printf("Error to allocate memory\n");
                return 0;
            }
        }
        srand(time(NULL));
        for (int i = 0; i < 4; i++)
            for(int j = 0; j < 3; j++)
                mat[i][j] = rand() % 100;
                //assign random values to each element of the matrix
        for (int i = 0; i < 4 * 3; i++) {
            for(int j = 0; j < 3; j++)
                printf("%2d ", mat[i][j]);
            printf("\n");
        }
        //free the allocated memory
        for(int i = 0; i < 4; i++)
            free(mat[i]);
        free(mat);
    } else {
        printf("Error to allocate memory\n");
    }

    
    return 0;
}