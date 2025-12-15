#include <stdio.h>
#include <stdlib.h>
#define SIZE 50

void binary(int n, int *array, int index) {
    if(n != 0) {
        binary(n/2, array, index -1);
        array[index] = n%2;
    }
}

void print_bin(int array[SIZE]) {
    for(int i = 0; i < SIZE; i++) {
        printf("%d", array[i]);
    }
    printf("\n");
}

int main(void) {
    int n, array[SIZE];

    for(int i = 0; i < SIZE; i++) {
        array[i] = 0;
    }

    printf("Enter a decimal number: ");
    while ((scanf("%d", &n)) != 1);

    binary(n, array, SIZE - 1);

    print_bin(array);

    return EXIT_SUCCESS;
}