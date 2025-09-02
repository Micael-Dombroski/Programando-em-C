#include <stdio.h>
#include <stdlib.h>
int** getMatrix(char *fileName) {
    FILE *file;
    file = fopen(fileName, "r");
    if(file) {
        char letter;
        int row = 0, col = 0;
        while((letter = fgetc(file)) != EOF) {
            if(letter == ',' && row == 0)
                col++;
            if(letter == '\n') {
                row++;
                if(row == 1) col++; 
            }
        }
        row++;
        int **mat;
        mat = calloc(row, sizeof(int*));
        if(mat) {
            for (int i = 0; i < row; i++) {
                mat[i] = calloc(col, sizeof(int));
                if(!mat[i]) {
                    printf("\n\t--> Error: memory allocation failded.\n");
                    fclose(file);
                    return NULL;
                }
            }
        } else {
            printf("\n\t--> Error: memory allocation failded.\n");
            fclose(file);
            return NULL;
        }
        rewind(file);
        char num[32];
        int index = 0;
        col = 0;
        row = 0;
        while((letter = fgetc(file)) != EOF) {
            if(letter == ',' || letter == '\n') {
                num[index] = '\0';
                *(*(mat + row) + col) = atoi(num);
                index = 0;
                if(letter == ',')
                    col++;
                if(letter == '\n') {
                    row++;
                    col = 0;
                }
            } else {
                num[index++] = letter;
            }
        }
        if(index > 0) {
            num[index] = '\0';
            *(*(mat + row) + col) = atoi(num);
        }
        fclose(file);
        return mat;
    } else {
        fclose(file);
        printf("\n\t--> Failed to open file!\n");
        return NULL;
    }
}
void printMatrix(int **mat, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
            printf("%5d ", *(*(mat + i) + j));
        printf("\n");
    }
}
void registerMultMatrix(int **m1, int r1, int c1, int **m2, int r2, int c2) {
    if(c1 != r2)
        return;
    int **m3;
    m3 = calloc(r1, sizeof(int*));
    if(m3) {
        for(int i = 0; i < r1; i++) {
            m3[i] = calloc(c2, sizeof(int));
            if(!m3[i]) {
                printf("\n\t--> Error: memory allocation failded.\n");
                return;
            }
        }
        for(int i = 0; i < r1; i++)
            for (int j = 0; j < c2; j++)
                for (int k = 0; k < c1; k++)
                    *(*(m3 + i) + j) += *(*(m1 + i) + k) * *(*(m2 + k) + j);
        FILE *file;
        file = fopen("mult-matrix.txt", "w+");
        if(file) {
            for (int i = 0; i < r1; i++)
            {
                for (int j = 0; j < c2; j++)
                {
                    fprintf(file, "%d", m3[i][j]);
                    if (j + 1 != c2) {
                        fprintf(file, ",");
                    }
                }
                if(i + 1 != r1) {
                    fprintf(file, "\n");
                }
            }
            fclose(file);
        } else {
            fclose(file);
            printf("\n\t--> Failed to open file!\n");
        }
    } else {
        printf("\n\t--> Error: memory allocation failded.\n");
    }
}
int main(void) {
    int **mat1 = getMatrix("matrix1.txt");
    int **mat2 = getMatrix("matrix2.txt");
    registerMultMatrix(mat1, 2, 3, mat2, 3, 4);
    int **result = getMatrix("mult-matrix.txt");
    printf("\n\tMatrix 1\n");
    printMatrix(mat1, 2, 3);
    printf("\n\tMatrix 2\n");
    printMatrix(mat2, 3, 4);
    printf("\n\tMultiplication of Matrix 1 and Matrix 2\n");
    printMatrix(result, 2, 4);
    for(int i = 0; i < 2; i++) {
        free(mat1[i]);
        free(result[i]);
    }
    for(int i = 0; i < 3; i++)
        free(mat2[i]);
    free(mat1);
    free(mat2);
    free(result);
    return 0;
}