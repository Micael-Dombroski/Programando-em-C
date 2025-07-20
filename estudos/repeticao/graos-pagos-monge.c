#include <stdio.h>
#include <stdlib.h>
int main(void) {
    long double qtdGraosNaCasa = 1, totalGraos = 1;
    for (int i = 2; i <= 64; i++)
    {
        qtdGraosNaCasa = qtdGraosNaCasa*2;
        totalGraos += qtdGraosNaCasa;
        __mingw_printf("%.2Lf graos\n", qtdGraosNaCasa);
        //windows não consegue escrever numeros desse tamanho
        //por isso temos que recorrer a essa função
    }
    __mingw_printf("A quantidade de graos que a rainha deve pagar ao monge e: %.2Lf graos\n", totalGraos);
    return 0;
}