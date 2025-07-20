#include <stdio.h>
#include <stdlib.h>
int totalGuardado(int valorInicial, int totalDias) {
    int totalGuardado = 0;
    int valorASerGuardado = valorInicial;
    for (int i = 1; i <= totalDias; i++)
    {
        totalGuardado+= valorASerGuardado;
        printf("Dia: %d, valor guardado R$ %.2f, total guardado R$ %.2f\n", i, valorASerGuardado/100.0, totalGuardado/100.0);
        valorASerGuardado= valorASerGuardado*2;
    }
    return totalGuardado;
}
int main(void) {
    int valorInicial=1, valorFinal=0;
    valorFinal = totalGuardado(valorInicial, 30);
    printf("Valor guardado no primeiro dia: R$ 0.01\n");
    printf("Dobrando o valor guardado por 30 dias\n");
    printf("O valor total guardado e: R$ %.2f\n", valorFinal/100.0);
    return 0;
}