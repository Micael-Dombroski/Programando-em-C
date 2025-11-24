#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 25

int main(void) {
    srand(time(NULL));
    int nums[SIZE];
    for(int i = 0; i < SIZE; i++) {
        nums[i] = rand() % 100;
    }
    for(int i = 0; i < SIZE; i++) {
        if(i % 5 == 0) {
            printf("\n");
        }
        printf("\t%2d", nums[i]);
    }
    int even_sum = 0, even_qtt = 0;
    for(int i = 0; i < SIZE; i++) {
        if(!(nums[i] & 1)) {
            even_qtt++;
            even_sum += nums[i];
        }
    }
    double even_avrg = (double) even_sum / even_qtt;
    printf("\n\n\tTotal of even numbers: %d\n\tThe average of the even numbers: %.2f\n", even_qtt, even_avrg);
    return EXIT_SUCCESS;
}