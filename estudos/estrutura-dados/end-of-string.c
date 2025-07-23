#include <stdio.h>
#include <stdlib.h>
int main(void) {
    //How to find where does the string end?
    /*
        Just print the array until you get the char 
        '\0' that represents the end of the string
    */
    char words[20] = {"Hello World"};
    int count = 0;
    printf("Write something: \n");
    fgets(words, 20, stdin);
    //fgets methot save even the char '\n' (enter key)
    while (words[count] != '\0') {
        printf("%2d = %d\n", count, words[count]);
        count++;
        //use count var then increment it
    }
    printf("\n");
    return 0;
}