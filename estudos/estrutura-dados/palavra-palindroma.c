#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
    char palavra[25];
    printf("Escreva uma palavra: \n");
    scanf("%25[^\n]", palavra); //lê os próximos 25 char ou até antes do '\n'
    strlwr(palavra);
    /*int tam = strlen(palavra);
    char palavraReversa[25];
    palavraReversa[0] = '\0';
    for(int i = tam-1; i >= 0; i--) {
        char temp[2] = {palavra[i], '\0'};
        strcat(palavraReversa, temp);
    }
    printf("Palavra: %s\tTamanho: %d\n", palavra, strlen(palavra));
    printf("Palavra reversa: %s\tTamanho: %d\n", palavraReversa, strlen(palavraReversa));
    printf("E palindroma: ");
    printf("%s", strcmp(palavra, palavraReversa) == 0 ? "True" : "False");*/
    
    int i = 0, diferentes = 0, tam = strlen(palavra);
    tam--;
    while(tam >= i) {
        if(palavra[i] != palavra[tam]) //mais eficiente, reduz as repetições
            diferentes++;
        i++;
        tam--;
    }
    if(diferentes == 0) printf("E palindroma\n");
    else printf("Nao e palindroma");
    
    return 0;
}