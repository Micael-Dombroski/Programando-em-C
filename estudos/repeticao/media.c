#include <stdio.h>
#include <stdlib.h>
float getNota(void) {
    float nota;
    printf("Informe a nota do aluno: \n");
    scanf("%f", &nota);
    return nota;
}
int notaValida(float nota) {
    if(nota < 0 || nota > 10)
        return 0;
    return 1;
}
float media(float nota1, float nota2) {
    float media = (nota1+nota2)/2;
    return media;
}
int main(void) {
    float nota1, nota2;
    do {
        nota1 = getNota();
        if(!notaValida(nota1))
            printf("A nota deve ser entre 0 e 10\n");
    } while(!notaValida(nota1));
    do {
        nota2 = getNota();
        if(!notaValida(nota2))
            printf("A nota deve ser entre 0 e 10\n");
    } while(!notaValida(nota2));
    printf("A media entre as notas %f e %f e: %f\n", nota1, nota2, media(nota1,nota2));
}