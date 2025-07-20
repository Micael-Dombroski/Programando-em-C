#include <stdio.h>
#include <stdlib.h>
int main(void) {
    printf("Informe um valor limite para a contagem: \n");
    int num;
    scanf("%d", &num);
    for (int i = 1; i <= num; i+= 2)
    {
        for (int j = 6 + i; j >= 4 +  i; j--)
        {
            printf("I = %d   J = %d\n", i, j);
        }
    }
    return 0;
}