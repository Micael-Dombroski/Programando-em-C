#include <stdio.h>
#include <stdlib.h>
float mediaAlturaBaseIdadeMaiorQue(float alturas[], int idades[], int idade, int qtdAlunos) {
    float mediaAltura = 0.0;
    int qtdAlunosIdadeMaior = 0;
    for (int i = 0; i < qtdAlunos; i++)
    {
        if(idades[i] > idade) {
            mediaAltura += alturas[i];
            qtdAlunosIdadeMaior ++;
        }
    }
    mediaAltura = mediaAltura / qtdAlunosIdadeMaior;
    return mediaAltura;
}
float mediaIdadeBaseAlturaMenorQue(int idades[], float alturas[], float altura, int qtdAlunos) {
    float mediaIdade = 0.0;
    int qtdAlunosAlturaMenor = 0;
    for (int i = 0; i < qtdAlunos; i++)
    {
        if(alturas[i] < altura) {
            mediaIdade += idades[i];
            qtdAlunosAlturaMenor ++;
        }
    }
    printf("media idade: %f\n", mediaIdade);
    printf("qtd de alunos menores: %d\n", qtdAlunosAlturaMenor);
    mediaIdade = mediaIdade / qtdAlunosAlturaMenor;
    return mediaIdade;
}
int main(void) {
    int qtdAlunos = 4;
    int idades[qtdAlunos];
    float alturas[qtdAlunos];
    int idade;
    float idadeMedia, alturaMedia, altura;
    for (int i = 0; i < qtdAlunos; i++)
    {
        printf("Digite sua idade: \n");
        scanf("%d", &idade);
        idades[i] = idade;
        printf("Digite sua altura em metros: \n");
        scanf("%f", &altura);
        alturas[i] = altura;
    }
    idadeMedia = mediaIdadeBaseAlturaMenorQue(idades, alturas, 1.70, qtdAlunos);
    alturaMedia = mediaAlturaBaseIdadeMaiorQue(alturas, idades, 20, qtdAlunos);
    printf("A media da idade dos alunos menores de 1.70 metros e: %.2f\n", idadeMedia);
    printf("A media de altura dos alunos maiores de 20 anos e: %.2f\n", alturaMedia);
    return 0;
}