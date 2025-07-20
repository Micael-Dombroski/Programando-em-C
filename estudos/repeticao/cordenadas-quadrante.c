#include <stdio.h>
#include <stdlib.h>
int getQuadrante(int x, int y) {
    if(x > 0 && y > 0)
        return 1;
    else if(x < 0 && y > 0)
        return 2;
    else if(x < 0 && y < 0)
        return 3;
    else if(x > 0 && y < 0)
        return 4;
    return 0;
}
int main(void) {
    int x =0, y = 0, quadrante;
    do {
        printf("Informe a coordenada X do ponto: \n");
        scanf("%d", &x);
        printf("Informe a coordenada Y do ponto: \n");
        scanf("%d", &y);
        quadrante= getQuadrante(x,y);
        if(quadrante != 0) {
            printf("O ponto presente nas coordenadas X = %d e Y = %d pertence ao %s quadrante\n\n",x, y, quadrante == 1 ? "Primeiro" : quadrante == 2 ? "Segundo" : quadrante == 3 ? "Terceiro" : "Quarto");
        }
    } while(quadrante != 0);
    return 0;
}