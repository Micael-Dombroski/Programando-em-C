#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
    char words[50] = "Once upon a time...";
    printf("String size: %d\n", strlen(words));
    strcat(words, "a king from farland");
    /*
        strcat takes 2 string as arguments.
        The function concatenates string1 and string2,
        and then string1 reveices the result of the
        concatenation
    */
    printf("\n\t%s\n", words);
    printf("String size: %d\n", strlen(words));
    
    return 0;
}