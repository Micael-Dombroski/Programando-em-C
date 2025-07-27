#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
    char word1[20] = "Once upon a time...";
    char word2[20] = "a king from farland";
    char word3[20] = "A king from farland";
    printf("\nResult: %s\n", strcmp(word1, word2) == 0 ? "equals" : "differents");
    /*
        strcmp return 
        -  0 if the string are equals
        -  1 if str1 is greater than str2
        - -1 if str1 is lower than str2
        A string is greater if the 1st different char between
        the strings have a greater value based on ASCII comparison
    */
    return 0;
}