#include <stdio.h>
#include <stdlib.h>
void contar(int x, int y) {
    for (int i = 1; i <= y; i++)
    {
        printf("%3d ", i);
        if(i%x == 0) printf("\n");
    }
}
int main(void) {
    int x = 0, y = 0;
    printf("Informe dois numeros: \n");
    scanf("%d%d", &x, &y);
    contar(x,y);
    return 0;
}