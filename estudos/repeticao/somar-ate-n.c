#include <stdio.h>
#include <stdlib.h>
int somarAteN(int n) {
    int soma = 0;
    for (int i = 1; i <= n; i++)
    {
        soma+= i;
    }
    return soma;
}
int main(void) {
    int n=0;
    do {
        printf("Informe o valor de N: \n");
        scanf("%d", &n);
    } while(n < 1);
    printf("A soma dos numeros de 1 ate %d e : %d\n", n, somarAteN(n));
    return 0;
}