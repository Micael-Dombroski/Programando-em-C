#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
    char word1[20] = "apple";
    char word2[20] = "driver";
    printf("\nResult: %s\n", strcmp(word1, word2) == 0 ? "equals" : "differents");
    strcpy(word1, word2);
    printf("\nResult: %s\n", strcmp(word1, word2) == 0 ? "equals" : "differents");
    /*
        You can't just repass the value of a string to another like a = b
        because string don't contain a single value (array of chars).
        You can use the function ctrcpy to copy the 2nd string to the 1st string
    */
    return 0;
}