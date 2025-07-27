#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
    char words[20] = "Once upon a time...";
    printf("String size: %d\n", strlen(words));
    //with strlen() we can know the size of a string
    /*
        if the program receives the string as input from the user
        it'll contain '\n', even if you write "hello", the size it's
        length will be 5; if you don't want that, create a loop to go
        through the string until you find the '\n' and then change it 
        to '\0'
    */
    return 0;
}