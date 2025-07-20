#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//vetores ou arrays unidimensionais
/*
    conjunto de elementos do mesmo tipo armazenados
    sequencialemente na memória
    -usamos indices para acessar cada elemento do vetor
*/
int main() {
    int num1[10];
    int num2[] = {1,5,9,15,43};
    int num3[5] = {3,7,5}; 
    //apesar de declarar só 3 valores o tamanho ainda é 5
    //os espaços faltantes recebem 0
    int num4[5] = {1,2,3,4,5,6};
    //ignora o tamanho do conjunto e preenche apenas até o tamanho do 
    //vetor, a sobra é perdida
    int num[5] = {0};
    //isso garante que todo o vetor seja ocupado com 0, sem lixo de memória
    char letras[100];
    char vogais[5] = {'a','e','i','o','u'};
    float notas[3] = {7.5,8.3,9.5};
    
    int tamanho = sizeof(num2) / sizeof(num2[0]);
    //o sizeof pega o total de bytes (cada int tem 4 bytes, por exemplo)
    //ent precisamos dividir o total pela qtd de bytes de 1 elemento, já 
    //que todos tem o mesmo tamanho em bytes, assim obtendo qntos elementos há
    for(int i = 0; i < tamanho; i++)
        printf("%d ", num2[i]);

    printf("\n");
    tamanho = sizeof(notas) / sizeof(notas[0]);
    for(int i = 0; i < tamanho; i++)
        printf("%.2f ", notas[i]);
    
    printf("\n");
    /*

    tamanho = sizeof(num)/sizeof(num[0]);
    for(int i = 0; i < tamanho; i++) {
        printf("Informe o numero %d: ", i+1);
        scanf("%d", &num[i]);
        printf("\n");
    }

    for(int i = 0; i < tamanho; i++)
        num[i] = num[i] * (i+1);

    printf("Numeros informados multiplicados por sua posicao: \n");
    for(int i = 0; i < tamanho; i++)
        printf("%d ", num[i]);
    printf("\n");

    */
    int randomNum[10];
    tamanho = sizeof(randomNum)/sizeof(randomNum[0]);

    srand(time(NULL));
    //define o valor base para os valores pseudo-aleatorios da rand()
    //usei time pois é um valor que sempre muda, fazendo os numeros
    //parecerem mais random

    for(int i = 0; i < tamanho; i++) 
        randomNum[i] = 1+ rand() % 100; //garante numeros gerandos entre 1 e 100
    //a funcao rand() gera um numero pseudo-aleatorio
    //pois os numeros gerados são sempre os mesmos
    printf("Numeros pseudo-aleatorios gerados: \n");
    for(int i = 0; i < tamanho; i++)
        printf("%d ", randomNum[i]);
    printf("\n");


    return 0;
}