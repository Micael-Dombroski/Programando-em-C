#include <stdio.h>
#include <stdlib.h>
void row(char simbol, int qtd) {
    for (int i = 0; i < qtd; i++)
    {
        printf("%c", simbol);
    }
    printf("\n");
}
int main(void) {
    char simbol = ' ';
    int simbPRow = 0, qtdRow = 0;
    printf("Informe o simbolo que deseja imprimir, quantos simbolos tera por linha e quantas linhas havera no total: \n");
    scanf("%c%d%d", &simbol, &simbPRow, &qtdRow);
    for (int i = 0; i < qtdRow; i++)
    {
        row(simbol, simbPRow);
    }
    return 0;
}