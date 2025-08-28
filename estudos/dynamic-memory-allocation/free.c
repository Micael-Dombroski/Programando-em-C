#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// For static memory, the program automatically releases it when it goes out of scope. 
// But with dynamic memory, the computer doesn't know when it is no longer needed. 
// Therefore, you must explicitly release it using free(). 
// free() -> deallocates memory previously allocated with malloc, calloc, or realloc.
// Dynamic memory is also automatically released when the program ends,
// but it's good practice to free it manually to avoid memory leaks during execution.

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
        free(arr);//realsing the memory previously allocated for arr
    } else {
        printf("Error to allocate memory\n");
    }
    return 0;
}