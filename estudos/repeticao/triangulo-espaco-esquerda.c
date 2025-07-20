#include <stdio.h>
#include <stdlib.h>
void imprimirTriangulo(int tamanhoBase, char simbolo) {
    int qtdEspacovazio = tamanhoBase-1;
    for (int i = 1; i <= tamanhoBase; i++)
    {
        for (int j = 1; j <= qtdEspacovazio; j++)
        {
            printf(" ");
        }
        for (int k = 1; k <= tamanhoBase-qtdEspacovazio; k++) {
            printf("%c", simbolo);
        }
        printf("\n");
        qtdEspacovazio--;
    }
}
int main (void) {
    char simbolo;
    int tamanhoBase = -1;
    printf("Informe o simbolo usado para fazer o triangulo: \n");
    scanf("%c", &simbolo);
    do {
        printf("Informe a quantidade de simbolos que a base do triangulo deve ter: \n");
        scanf("%d", &tamanhoBase);
    } while(tamanhoBase < 0);
    imprimirTriangulo(tamanhoBase, simbolo);
    return 0;
}