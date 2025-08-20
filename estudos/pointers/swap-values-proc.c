#include <stdio.h>
#include <stdlib.h>
void swap(float *num1, float *num2) {
    float copy = *num1;
    *num1 = *num2;
    *num2 = copy;
}
int main (void) {
    float num1 = 9.5, num2 = 3.14;
    printf("Num1: %.2f\tNum2: %.2f\n", num1, num2);
    swap(&num1, &num2);
    printf("Num1: %.2f\tNum2: %.2f\n", num1, num2);
}