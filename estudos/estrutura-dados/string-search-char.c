#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
    char word[20] = "once upon a time...";
    char *letter;
    char c = 'e';
    /*
        strchr -> returns the 1st occurrence of the char
        strrchr -> returns the last occurrence of the char
    */
    letter = strchr(word, c);
    printf("First occurrence of %c: %c\n", c, *letter);
    printf("Next char from the 1st occurrance of %c: %c\n", c, *(letter + 1));
    //In an array, the values are stored in sequence in memory. 
    //If you use *(pointer + 1), you access the value in the next position.
    letter = strrchr(word, c);
    printf("Last occurrence of %c: %c\n", c, *letter);
    printf("Next char from the last occurrance of %c: %c\n", c, *(letter + 1));
    letter = strrchr(word, 'z'); //receives NULL because 'z' isn't in the string
    printf("%p\n", letter);
    return 0;
}