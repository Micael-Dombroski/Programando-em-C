#include <stdio.h>
#include <stdlib.h>
int main(void) {
    float valor[10], valorTotVendas = 0.0;
    int qtdVendas[10], retorno, maiorQtdVend = 0;
    for(int i = 0; i < 10; i++) {
        do {
            char c;
            printf("Informe o valor do produto %d e a quantidade vendida desse produto: \n", i+1);
            retorno = scanf("%f%d", &valor[i], &qtdVendas[i]);
            while((c = getchar()) != '\n');
        } while(retorno != 2);
        if(maiorQtdVend < qtdVendas[i]) maiorQtdVend = qtdVendas[i];
    }
    printf("Produto   | Unidade | Vendas | Total\n");
    for (int i = 0; i < 10; i++)
    {
        float totalVendasProduto = valor[i]* qtdVendas[i];
        valorTotVendas += totalVendasProduto;
        printf("Produto%2d | %7.2f | %6d | %.2f\n", i+1, valor[i], qtdVendas[i], totalVendasProduto);
    }
    printf("Valor total de vendas: %.2f\n", valorTotVendas);
    printf("Comissao paga ao vendedor: %.2f\n", valorTotVendas*0.05);
    printf("\n\nProduto(s) mais vendido(s)\n");
    printf("Produto   | Unidade | Vendas\n");
    for (int i = 0; i < 10; i++)
        if(qtdVendas[i] == maiorQtdVend) printf("Produto%2d | %7.2f | %d\n", i+1, valor[i], qtdVendas[i]);
    return 0;
}