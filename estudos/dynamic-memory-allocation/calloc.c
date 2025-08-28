#include <stdio.h>
#include <stdlib.h>//provides functions for dynamic memory allocation
int main(void) {
    char *x;
    x = calloc(1, sizeof(char));
    // calloc has 2 parameters: 
    // (1) the number of elements to allocate, and 
    // (2) the size of each element (in bytes).
    // It allocates the total block (num * size), initializes it to zero, 
    // and returns a pointer to the memory (or NULL if it fails).
    if(x) {
        printf("Successfully allocated memory block\n");
        printf("x: %c\n", *x);
        //unlike malloc, calloc initialize the allocated memory to zero, so 
        //it doesn't cointain garbage values
        *x = 'V';
        printf("x: %c\n", *x);
    } else {
        printf("Error to allocate memory\n");
    }
    return 0;
}