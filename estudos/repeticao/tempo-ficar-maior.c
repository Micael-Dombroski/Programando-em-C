#include <stdio.h>
#include <stdlib.h>
float newSize(float currentSize, float sizeIncrement) {
    float size = currentSize + sizeIncrement;
    return size;
}
int main(void) {
    float zeSize = 1.10, chicoSize = 1.50;
    float zeSizeInc = 0.03, chicoSizeInc = 0.02;
    int qtdYears = 0;
    printf("Tamanho do Ze - Tamanho do Chico\n");
    do {
        zeSize = newSize(zeSize, zeSizeInc);
        chicoSize = newSize(chicoSize, chicoSizeInc);
        qtdYears++;
        printf(" %.2f metros  -   %.2f metros   \n", zeSize, chicoSize);
    } while (zeSize <= chicoSize);
    printf("\nLevou %d anos para o Ze ficar maior que o Chico\n", qtdYears);
    return 0;
}