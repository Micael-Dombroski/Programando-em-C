#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void) {
    int *arr;
    int size, ret;
    char c;
    do {
        printf("Enter the array size: \n");
        ret = scanf("%d", &size);
        while((c = getchar()) != '\n');
    } while(ret != 1 || size < 1);
    //arr = malloc(sizeof(int) * size);
    arr = calloc(size, sizeof(int));
    /*
        In C, arrays are static: their size is fixed at compile 
        time, which may cause insufficient space or wasted memory. 
        Dynamic arrays solve this by allocating memory at runtime, 
        allowing their size to be adjusted during program execution.
    */
    if(arr) {
        srand(time(NULL));
        for (int i = 0; i < size; i++)
            *(arr + i) = rand() % 100;
        for (int i = 0; i < size; i++)
            printf("%d ", *(arr + i));
        printf("\n"); 
    } else {
        printf("Error to allocate memory\n");
    }
    return 0;
}