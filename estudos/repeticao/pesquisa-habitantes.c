#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main(void) {
    char sexo = ' ';
    float salario = 0.0, somaSalarial = 0.0;
    int n = 0, qtdMulheresSalarioMenor = 0, idade =0, maiorIdade = 0, menorIdade = 99999;
    do {
        printf("Informe a quantidade de habitantes que tiveram seus dados coletados na regiao: \n");
        scanf("%d", &n);
    } while(n < 0);
    for (int i = 1; i <= n; i++)
    {
        printf("Informe a idade do habitante: \n");
        scanf("%d", &idade);
        getchar();
        if(idade > maiorIdade)
            maiorIdade = idade;
        if(idade < menorIdade)
            menorIdade = idade;
        printf("Informe o sexo do habitante (M/F): \n");
        scanf("%c", &sexo);
        getchar();
        printf("Informe o salario do habitante: \n");
        scanf("%f", &salario);
        getchar();
        somaSalarial += salario;
        if(toupper(sexo) == 'F' && salario <= 2000.00)
            qtdMulheresSalarioMenor++;
    }
    printf("A media de salario dos habitantes e: %.2f\n", somaSalarial/n);
    printf("Maior idade registrada: %d\nMenor idade registrada: %d\n", maiorIdade, menorIdade);
    printf("Quantidade de mulheres com salario de ate 2000 reais: %d\n", qtdMulheresSalarioMenor);
    return 0;
}