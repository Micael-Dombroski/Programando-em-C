#include <stdio.h>
#include <stdlib.h>
int main(void) {
    long double num[10];
    int retorno;
    for(int i = 0; i < 10; i++) {
        do {
            char c;
            printf("Informe o valor %d: \n", i+1);
            retorno = scanf("%lf", &num[i]);
            while((c = getchar()) != '\n');
        } while(retorno != 1);
    }
    int opt = -1;
    do {
        printf("==================Menu==================\n");
        printf("0 - Finalizar programa\n");
        printf("1 - Imprimir numeros inseridos\n");
        printf("2 - Imprimir numeros inseridos [reverso]\n");
        do {
            char c;
            printf("Informe a opcao desejada: \n");
            retorno = scanf("%d", &opt);
            while((c = getchar()) != '\n');
        } while (retorno != 1);
        switch (opt)
        {
        case 0:
            printf("Finalizando o programa...\n");
            break;
        case 1:
            printf("Imprimindo valores inseridos: \n");
            for (int i = 0; i < 10; i++)
                printf("%lf - ", num[i]);
            printf("\n");
            break;
        case 2:
            printf("Imprimindo valores inseridos [reverso]: \n");
            for (int i = 9; i >= 0; i--)
                printf("%lf - ", num[i]);
            printf("\n");
            break;
        default:
            printf("Opcao invalida\n");
            break;
        }
    } while(opt != 0);
}