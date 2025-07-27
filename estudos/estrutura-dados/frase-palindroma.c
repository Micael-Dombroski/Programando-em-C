#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
    char frase[50], copia[50];
    copia[0] = '\0';
    printf("Escreva uma frase: \n");
    scanf("%50[^\n]", frase); //ler no max 50 char ou até antes do '\n'
    strlwr(frase);
    int j = 0;
    for(int i = 0; i < strlen(frase); i++) {
        while(frase[i] == ' ' || frase[i] == '!' || 
              frase[i] == ',' || frase[i] == '.' ||
              frase[i] == '?') i++;
        copia[j++] = frase[i];
    }
    copia[j] = '\0';
    int count = 0, diferentes = 0, tam = strlen(copia);
    tam--;
    while(tam >= count) {
        if(copia[count] != copia[tam]) {//mais eficiente, reduz as repetições
            diferentes++;
            break;
        }
        count++;
        tam--;
    }
    printf("Original: %s\n", frase);
    printf("Copia: %s\n", copia);
    if(diferentes == 0) printf("E palindroma\n");
    else printf("Nao e palindroma\n");
    
    return 0;
}