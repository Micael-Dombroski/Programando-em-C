#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// realloc (re-allocation) -> changes the size of a previously allocated memory block. 
// It can increase or decrease the block size, preserving existing values when possible. 
// Commonly used to resize dynamic arrays.
int main(void) {
    int *arr;
    int size, ret;
    char c;
    do {
        printf("Enter the array size: \n");
        ret = scanf("%d", &size);
        while((c = getchar()) != '\n');
    } while(ret != 1 || size < 1);
    arr = calloc(size, sizeof(int));
    if(arr) {
        srand(time(NULL));
        for (int i = 0; i < size; i++)
            *(arr + i) = rand() % 100;
        for (int i = 0; i < size; i++)
            printf("%d ", *(arr + i));
        printf("\n"); 
        do {
            printf("Enter the new array size: \n");
            ret = scanf("%d", &size);
            while((c = getchar()) != '\n');
        } while(ret != 1 || size < 1);
        arr = realloc(arr, size);
        for (int i = 0; i < size; i++)
            printf("%d ", *(arr + i));
        printf("\n"); 
    } else {
        printf("Error to allocate memory\n");
    }
    return 0;
}