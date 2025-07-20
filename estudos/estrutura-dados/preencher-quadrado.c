#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int v1[10];
    int v2[10];
    int retorno;
    char c;
    for (int i = 0; i < 10; i++)
    {
        do {
            printf("Informe o numero %d: \n", i+1);
            retorno = scanf("%d", &v1[i]);
            while((c = getchar()) != '\n');
        } while(retorno != 1);
    }
    for (int i = 0; i < 10; i++)
    {
        v2[i] = v1[i]*v1[i];
    }
    for (int i = 0; i < 10; i++)
    {
        printf("Posicao %d: %d\n", i, v2[i]);
    }
    return 0;
}