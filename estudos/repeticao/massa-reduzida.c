#include <stdio.h>
#include <stdlib.h>
int tempoReducaoMassa(float massaInicial) {
    float massaAtual = massaInicial;
    int tempoLevado=0.0;
    for (tempoLevado; massaAtual >= 0.05; tempoLevado+=50)
    {
        printf("Massa atual e %f gramas, tempo passado: %d segundos\n", massaAtual, tempoLevado);
        massaAtual=massaAtual/2;      
    }
    printf("Massa atual e %f gramas, tempo passado: %d segundos\n", massaAtual, tempoLevado);
    return tempoLevado;
}
int main(void) {
    float massa = 0.0;
    do {
        printf("Informe o valor da massa do material radioativo: \n");
        scanf("%f", &massa);
    } while(massa < 0.05);
    printf("O material radiotivo de massa %f gramas levou %d segundos para ficar com massa menor que 0.05 gramas\n", massa, tempoReducaoMassa(massa));
    return 0;
}