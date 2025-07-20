#include <stdio.h>
#include <stdlib.h>
void imprimirTriangulo(int tamanhoBase, char simbolo) {
    for (int i = tamanhoBase; i >= 0; i--)
    {
        for (int j = 1; j <= i; j++)
            printf("%c", simbolo);
        printf("\n");
    }
}
int main (void) {
    char simbolo, letra;
    int tamanhoBase = -1;
    printf("Informe o simbolo usado para fazer o triangulo: \n");
    scanf("%c", &simbolo);
    do {
        printf("Informe a quantidade de simbolos que a base do triangulo deve ter: \n");
        scanf("%d", &tamanhoBase);
        do { //limpando o buffer de entrada
            letra = getchar(); 
        } while(letra != '\n');
    } while(tamanhoBase < 0);
    imprimirTriangulo(tamanhoBase, simbolo);
    return 0;
}