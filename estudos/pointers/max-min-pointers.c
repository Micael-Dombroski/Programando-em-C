#include <stdio.h>
#include <stdlib.h>
//procedure that assign the largest value in the array to "max" and the
//smallest value to "min" using pointers to their addresses.
void getMinAndMaxValues (int arr[], int size, int *min, int *max) {
    *min = arr[0], *max = arr[0];
    for(int i = 1; i < size; i++) {
        if(arr[i] < *min)
            *min = arr[i];
        if(arr[i] > *max)
            *max = arr[i];
    }
}
//procedure that prints the values stored in the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main (void) {
    int arr[10] = {0,2,0,-2,5,8,-3,1,7, 4}, size = 10, min, max;
    printf("Array: ");
    printArray(arr, size);
    getMinAndMaxValues(arr, size, &min, &max);
    printf("Smallest value: %d\tLargest value: %d\n", min, max);
    return 0;
}