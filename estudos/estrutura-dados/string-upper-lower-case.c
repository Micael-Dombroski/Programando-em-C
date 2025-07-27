#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
    char word[20] = "Once Upon a Time...";
    /*
        strupr -> convert the string to upper case
        strlwr -> convert the string to lower case
    */
    printf("Original string: %s\n", word);
    strupr(word);
    printf("Upper Case: %s\n", word);
    strlwr(word);
    printf("Lower Case: %s\n", word);

    
    return 0;
}