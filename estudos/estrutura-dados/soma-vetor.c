#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void) {
    int v1[25];
    int v2[25];
    int v3[25];
    srand(time(NULL));
    for(int i = 0; i < 25; i++) {
        v1[i] = rand()%100+1;
        v2[i] = rand()%100+1;
    }
    for(int i = 0; i < 25; i++)
        v3[i] = v1[i] + v2[i];
    printf("\nVetor 1\n");
    for(int i = 0; i < 25; i++)
        printf("%3d ", v1[i]);
    printf("\nVetor 2\n");
    for(int i = 0; i < 25; i++)
        printf("%3d ", v2[i]);
    printf("\nVetor 3\n");
    for(int i = 0; i < 25; i++)
        printf("%3d ", v3[i]);
    return 0;
}