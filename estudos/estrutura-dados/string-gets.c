#include <stdio.h>
#include <stdlib.h>
int main(void) {
    char palavras[10] = {"ThisString"};
    printf("Digite seu nome: ");
    gets(palavras);
    /*
        A função gets() não é segura
        Não é possível controlar a quantidade 
        de caracteres inseridos, podendo sobrepor
        outras variaveis na memoria
    */
    printf("\nOla %s\n", palavras);
    return 0;
}