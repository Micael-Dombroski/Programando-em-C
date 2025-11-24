#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 50

int main(void) {
    int i, array[SIZE], highestIndex = 0;
    srand(time(NULL));
    for(i = 0; i < SIZE; i++) {
        array[i] = rand() % 10000;
    }
    double highest = 0, quotient;
    for(i = 1; i < SIZE; i++) {
        quotient = (double) array[i] / i;
        if(highest < quotient) {
            highest = quotient;
            highestIndex = i;
        }
    }
    for(i = 0; i < SIZE; i++) {
        printf("\t%d\t%d\n", i, array[i]);
    }
    printf("The highest quotient is: %.2f with array value %d at index %d\n", highest, array[highestIndex], highestIndex);
    return EXIT_SUCCESS;
}