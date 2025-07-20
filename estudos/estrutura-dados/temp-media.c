#include <stdio.h>
#include <stdlib.h>
char* printMes(int num) {
    switch (num)
    {
    case 0: return "janeiro";
    case 1: return "fevereiro";
    case 2: return "marco";
    case 3: return "abril";
    case 4: return "maio";
    case 5: return "junho";
    case 6: return "julho";
    case 7: return "agosto";
    case 8: return "setembro";
    case 9: return "outubro";
    case 10: return "novembro";
    case 11: return "dezembro";
    default: return "invalido";
    }
}
int main(void) {
    float tempMedia[12]= {0}, maior, menor;
    int retorno, mesMaior, mesMenor;
    for (int i = 0; i < 12; i++)
    {
        do {
            char c;
            printf("Informe a temperatura media do Mes %d: \n", i+1);
            retorno = scanf("%f", &tempMedia[i]);
            while ((c = getchar()) != '\n');
        } while(retorno != 1);
        if(i == 0) {
            maior = tempMedia[i];
            mesMaior = i;
            menor = tempMedia[i];
            mesMenor = i;
        }
        if(maior < tempMedia[i]) {
            maior = tempMedia[i];
            mesMaior = i;
        }
        if(menor > tempMedia[i]) {
            menor = tempMedia[i];
            mesMenor = i;
        }
    }
    printf("A maior temperatura do ano foi de %.2f C no mes de %s\n", maior, printMes(mesMaior));
    printf("A menor temperatura do ano foi de %.2f C no mes de %s\n", menor, printMes(mesMenor));
    return 0;
}