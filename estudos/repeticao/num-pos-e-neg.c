#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int qtdPos = 0, qtdNeg = 0, num = 0;
    do {
        printf("Informe um numero inteiro (digite 0 para finalizar): \n");
        scanf("%d", &num);
        if (num > 0)
            qtdPos++;
        if(num < 0)
            qtdNeg++;
    } while(num != 0);
    printf("Quantidade de numeros positivos digitados: %d\n", qtdPos);
    printf("Quantidade de numeros negativos digitados: %d\n", qtdNeg);
    return 0;
}