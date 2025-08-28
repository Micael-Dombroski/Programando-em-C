#include <stdio.h>
#include <stdlib.h>//provides functions for dynamic memory allocation
// Why "dynamic"? Because the memory is allocated at runtime, not at compile time.
// malloc (memory allocation) -> Allocates a block of memory of given size (in bytes) 
// and returns a pointer to the beginning of the block, or NULL if the allocation fails.
int main(void) {
    int *x;
    x = malloc(sizeof(int));
    if(x) {
        printf("Successfully allocated memory block\n");
        printf("x: %d\n", *x);//it'll show memory garbage
        *x = 50;
        printf("x: %d\n", *x);
    } else {
        printf("Error to allocate memory\n");
    }
    return 0;
}