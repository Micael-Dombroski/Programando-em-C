#include <stdio.h>
#include <stdlib.h>
float getSalario(int numeroFuncionario) {
    float salario = 0.0;
    printf("Informe o salario do funcionario %d: \n", numeroFuncionario);
    scanf("%f", &salario);
    return salario;
}
int main(void) {
    int qtdFuncionario = 0;
    float totalSalarios = 0.0, maiorSalario = 0.0, menorSalario = 9999999;
    do {
        printf("Informe a quantidade de funcionarios da empresa: \n");
        scanf("%d", &qtdFuncionario);
    } while (qtdFuncionario < 0);
    for (int i = 1; i <= qtdFuncionario; i++)
    {
        float salario = getSalario(i);
        if(salario > maiorSalario)
            maiorSalario = salario;
        if(salario < menorSalario)
            menorSalario = salario;
        totalSalarios+= salario;
    }
    printf("A media salarial dos %d funcionarios da empresa e: %.2f reais\n", qtdFuncionario, totalSalarios/qtdFuncionario);
    printf("O maior salario registrado foi de %.2f reais\n", maiorSalario);
    printf("O menor salario registrado foi de %.2f reais\n", menorSalario);
    return 0;
}