#include <stdio.h>
#include <stdlib.h>
float getNota(int numNota) {
    float nota = 0.0;
    printf("Informe a nota da avaliacao %d: \n", numNota);
    scanf("%f", &nota);
    return nota;
}
int main(void) {
    int opt = -1;
    do {
        float nota1, nota2, media;
        do {
            nota1 = getNota(1);
        } while (nota1 > 10 || nota1 < 0);
        do {
            nota2 = getNota(2);
        } while (nota2 > 10 || nota2 < 0);
        media = (nota1+nota2)/2;
        printf("Nota avaliacao 1: %.2f\nNota avaliacao 2: %.2f\nMedia semestral: %.2f\n", nota1, nota2, media);
        printf("Novo calculo? [1] Sim , [2] Nao\n");
        scanf("%d", &opt);
    } while(opt != 2);
    return 0;
}