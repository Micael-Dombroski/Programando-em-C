#include <stdio.h>
#include <stdlib.h>
int main(void) {
    char palavras[10] = {"ThisString"}, c;
    int retorno;
    printf("Digite seu nome: ");
    do {
        //retorno = scanf("%s", palavras);
        retorno = scanf("%10[^\n]", palavras);
        //string não precisa do operador de endereço para atribuição
        //scanf por padrão lê até o primeiro espaço ou enter
        /* Como fazer ele ler os espaços?
            com "%[^\n]" garantimos que o scanf vai ler tudo até 
            o primeiro enter
        */
        /*
            scanf não leva em consideração o tamanho do vetor
            se o tamanho do vetor for menor que o valor que recebe
            os espaços da memória que seguem além do reservado pelo vetor
            serão sobrepostos, o que acarreta num erro
        */
        /* Como Resolver esse problema de sobreposição?
            com "%10[^\n]" garantimos que ele vai ler uma string
            de tamanho 10, incluindo os espeços, o resto não será 
            atribuído ao vetor
        */
        while((c = getchar()) != '\n');
    } while(retorno != 1);
    printf("\nOla %s\n", palavras);
    return 0;
}