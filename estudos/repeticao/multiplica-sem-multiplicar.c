#include <stdio.h>
#include <stdlib.h>
int multiplicaSemMultiplicar(int n1, int n2) {
    int valorFinal = 0;
    for(int i = 1; i <= n2; i++) {
        valorFinal +=n1;
    }
    return valorFinal;
}
int main(void) {
    int num1 = 0, num2 = 0;
    printf("Informe o numero que deseja multiplicar: \n");
    scanf("%d", &num1);
    do {
        printf("Informe a quantidade de vezes que deseja multiplicar o numero: \n");
        scanf("%d", &num2);
    } while (num2 < 0);
    printf("Multiplicando %d por %d temos o valor %d\n", num1, num2, multiplicaSemMultiplicar(num1,num2));
    return 0;
}