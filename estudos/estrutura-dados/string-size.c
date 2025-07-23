#include <stdio.h>
#include <stdlib.h>
int main(void) {
    //How to find the string size
    /*
        Just count until find the first '\0' char
    */
    char words[20];
    int size = 0, count = 0;
    printf("Write something: \n");
    fgets(words, 20, stdin);
    //fgets methot save even the char '\n' (enter key)
    //Removing char '\n' from the string
    while (words[count] != '\0') {
        if(words[count] == '\n')
            words[count] = '\0';
        count++;
        //use count var then increment it
    }
    //Counting the string size
    count = 0;
    while (words[count] != '\0') {
        size++;
        count++;
        //use count var then increment it
    }
    printf("\n");
    printf("String size: %d\n", size);
    return 0;
}