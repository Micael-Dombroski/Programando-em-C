#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void) {
    int tam = 25, count = 0;
    int vet[tam];
    srand(time(NULL));
    do {
        vet[count] = rand() % 50;//num de 0 a 49
        for(int i= 0; i < count; i++) {
            if(vet[count] == vet[i]) {
                count --;
                break;
            }
        }
        count ++;
    } while (count < tam);
    for(int i= 0; i < tam; i++) {
        printf("%2d ", vet[i]);
    }
    printf("\n");
    return 0;
}