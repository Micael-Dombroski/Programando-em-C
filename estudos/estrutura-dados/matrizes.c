#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//matrizes ou arrays bidimensionais
//conjunto de elementos do mesmo tipo
int main(void) {
    int mat1[3][3] = {1,2,3,4,5,6,7,8,9};
    //3 elementos ficam em cada "linha"
    int mat2[][3] = {0,0,0};
    //3 elementos por linha mas n sabe qntas linhas serao criadas
    //4 elementos = 2 linhas, 7 elementos = 3 linhas, 3 elementos = 1 linha...
    //caso falte elementos para preencher uma linha eles recebem valor 0
    int mat3[3][3] = {0}; //todos os elementos da matriz recebem 0

    char mat4[3][4] = {'a','b','c','d','e','f','g','h','i','j','k','l'};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", mat1[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
            printf("%c ", mat4[i][j]);
        printf("\n");
    }
    int resposta;
    char c;
    /*Preenchendo matriz com inputs do usuario
    int mat5[2][2] = {0};
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            do {
                printf("Informe o numero na posicao [%d][%d] da matriz: \n", i, j);
                resposta = scanf("%d", &mat5[i][j]);
                while((c = getchar()) != '\n'); //limpando buffer do teclado
            } while (resposta != 1);
        }   
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("[%d][%d] = %d\n", i, j, mat5[i][j]);
        }
        
    }
    */
    /*mostrando o valor da matriz
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("[%d][%d] = %d\n", i, j, mat1[i][j]);
        }
        
    }
    //alterando valor da matriz
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            mat1[i][j] = mat1[i][j]*2;
        }
        
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("[%d][%d] = %d\n", i, j, mat1[i][j]);
        }
        
    }
    */
    //alimentando matriz com numeros pseudo-random entre 1 e 100
    srand(time(NULL));//usado o tempo da máquina para gerar os números
    //precisamos da srand para q o pc n gere os mesmos numeros sempre
    int matriz[3][3];
    for(int i = 0; i < 3; i++)
        for(int j= 0; j < 3; j++) {
            matriz[i][j] = 1+ rand() % 100;
        }
    for(int i = 0; i < 3; i++)
        for(int j= 0; j < 3; j++) {
            printf("[%d][%d] = %3d\n", i, j, matriz[i][j]);
        }
    return 0;
}