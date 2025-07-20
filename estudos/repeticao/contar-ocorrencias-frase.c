#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int qtdOcorrencias(char str1[], char str2[]) {
    int i, j = 0, Ocorrencias = 0;
    for(i = 0; i < strlen(str1); i++) {
        if(str1[i] == str2[j]) {
            j++;
        } else {
            j = 0;
        }
        if(j == strlen(str2)) {
            Ocorrencias++;
            j = 0;
        }
    }
    return Ocorrencias;
}
int main(void) {
    char str1[] = "quem ama ama muito";
    char str2[] = "ama";
    printf("Qtde de ocorrencias da palavra na frase: %d\n", qtdOcorrencias(str1, str2));
    return 0;
}