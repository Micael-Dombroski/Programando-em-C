#include <stdio.h>
#include <stdlib.h>
void arrayShowValueAndAddress(int *value, int size) {
    for(int i = 0; i < size; i++)
        printf("Content: %d\tAddress: %p\n", *(value + i), (value + i));
} 
int main(void) {
    int arr[] = {0,1,2,3,4,5,6,7,8,9};
    arrayShowValueAndAddress(&arr[0], 10);
    return 0;
}