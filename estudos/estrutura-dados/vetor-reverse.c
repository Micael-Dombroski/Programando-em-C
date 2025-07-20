#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int vet[] = {14,52,36,54,78,84,91,16,18,24,57,55,32,39,76,81,46,43,48,29};
    int vetReverse[20];
    for(int i = 0; i < 20; i++)
        vetReverse[20-(i+1)] = vet[i];
    printf("\nOrdem Original\n");
    for(int i = 0; i < 20; i++)
        printf("%d ", vet[i]);
    printf("\nOrdem Inversa\n");
    for(int i = 0; i < 20; i++)
        vet[i] = vetReverse[i];
    for(int i = 0; i < 20; i++)
        printf("%d ", vet[i]);

    return 0;
}