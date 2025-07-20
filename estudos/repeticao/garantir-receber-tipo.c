#include <stdio.h>
#include <stdlib.h>
/** O que é um buffer de entrada?
 * É uma região da memória temporária que armazena dados digitados
 * antes de eles sejam lidos pelo programa, esses dados são armazenados
 * até serem processados por funções como scanf(), getchar(), fgets()
 * É importante limpar o buffer antes de usar novamente uma dessas funções
 * para obter dados para não ter comportamentos inesperados (loops infinitos,
 * leitura incorreta, etc)
 * Sempre que informamos um valor para uma dessas funções o ENTER é deixado
 * no buffer, devendo ser limpado antes do uso de outra função de input
 */
int main(void) {
    int valor, retorno = -1;
    char letra;
    do {
        printf("Digite um valor: ");
        retorno = scanf("%d", &valor); 
        //o scanf retorna 1 (se o valor informado
        //for do tipo esperado) ou 0 (caso não seja)
        printf("Retorno: %d\n", retorno);
        do {
            letra = getchar(); 
            //limpando os caracteres do buffer do teclado
            //pois o scan não vai receber valores enquanto
            //houver valores no buffer do teclado
        } while(letra != '\n');
        //loop enquanto não limpar a tecla ENTER ('\n') do buffer 
        //do teclado, pois ela sempre é a última presente nele
    } while (retorno == 0); 
    //loop enquanto o tipo do valor informado for diferente
    //do tipo esperado
    printf("Valor digitado: %d\n", valor);
    return 0;
}