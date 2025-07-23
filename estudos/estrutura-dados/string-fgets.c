#include <stdio.h>
#include <stdlib.h>
#define tam 10
int main(void) {
    char palavras[tam] = {"ThisString"};
    printf("Digite seu nome: ");
    fgets(palavras, tam, stdin);
    /*
        Muito usado para fazer a leitura de files
        Pede 3 paramentos:
        -variavel que vai armazenar a string
        -n maximo de caracteres lidos
        --uma string tem sempre o ultimo espaço reservado
            para o char de fime da string, essa função lê,
            sempre 1 a menos do tamanho limite ja reservando
            o espaço final para o char de fim de string ('\0'
            que representa nulo)
        -de qual arquivo será lida a string
        --stdin é a entrada padrão do pc (teclado)
    */
    printf("\nOla %s\n", palavras);
    return 0;
}