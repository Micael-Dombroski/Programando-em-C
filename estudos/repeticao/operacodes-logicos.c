#include <stdio.h>
#include <stdlib.h>
int main(void) {
    printf("& - avalia bit a bit, analisando todas as expressões independente dos resultados obtidos\n");
    printf("&& - avalia da esquerda para a direita, se o primeiro operando for igual a 0/false ele nem avalia o segundo\nIsso o torna mais eficiente que o &\n");
    printf("| - avalia bit a bit, analisando todas as expressões independente dos resultados obtidos\n");
    printf("|| - avalia da esquerda para a direita, se o primeiro operando for igual a 1/true ele nem avalia o segundo\nIsso o torna mais eficiente que o |\n");
}