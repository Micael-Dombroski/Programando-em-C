#include <stdio.h>
#include <stdlib.h>
int eprimo(int valor) {
    if(valor%2 == 0 || valor%3 == 0)
        if (valor != 3)
            return 0;
    for (int i = 5; i*i <= valor; i+=6)
    {
        if(valor % i == 0 || valor % (i + 2) == 0)
            return 0;
    }
    return 1;
}
int main(void) {
    int valor =0;
    do {
        printf("Informe um numero inteiro maior que 2: \n");
        scanf("%d", &valor);
    } while (valor <= 2);
    if(eprimo(valor)) {
        printf("O valor %d e primo\n", valor);
    } else {
        printf("O valor %d nao e primo\n", valor);
    }
    return 0;
}