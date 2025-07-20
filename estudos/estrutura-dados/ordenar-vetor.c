#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int vet[100] = {
        27, 4, 93, 56, 11, 62, 89, 34, 76, 21,
        68, 19, 40, 52, 78, 1, 17, 100, 95, 25,
        6, 38, 43, 13, 97, 84, 88, 2, 65, 59,
        31, 58, 70, 8, 46, 29, 35, 28, 71, 41,
        20, 7, 64, 75, 86, 14, 32, 80, 55, 73,
        5, 23, 67, 99, 60, 92, 30, 26, 10, 12,
        49, 45, 15, 87, 37, 66, 90, 36, 44, 22,
        79, 96, 91, 61, 83, 33, 18, 3, 74, 94,
        69, 9, 53, 81, 42, 63, 98, 24, 48, 47,
        72, 50, 16, 85, 39, 82, 77, 51, 57, 54
    };
    int bubble[100] = {0};
    for(int i = 0; i < 100; i++) {
        printf("%d - ", vet[i]);
        bubble[i] = vet[i];
    }
    //Bubble Sort
    int troca;
    do {
        troca = 0;
        for(int i = 0; i < 99; i++) {
        if(bubble[i] > bubble[i+1]) {
            int copia = bubble[i];
            bubble[i] = bubble[i+1];
            bubble[i+1] = copia;
            troca = 1;
        }
    }
    } while (troca); //verifica se houve troca, se não houver ent ja ta organizado
    printf("\n\n");

    for(int i = 0; i < 100; i++) {
        printf("%d - ", bubble[i]);
    }
    printf("\n\n");
    return 0;
}