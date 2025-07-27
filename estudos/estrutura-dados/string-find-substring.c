#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
    char word[20] = "once upon a time...";
    char str[] = {"upon"};
    char *letter;
    /*
        strstr -> try to find a substring in the string
    */
    letter = strstr(word, str);
    if(letter) {
        //check if letter != null
        printf("The string %s existis in %s?\n", str, word);
        char findWord [strlen(str) + 1];
        findWord[0] = '\0'; //essencial to use strcat after
        for(size_t i = 0; i < strlen(str); i++) {
            char temp[2] = {*(letter + i), '\0'};
            strcat(findWord, temp);
        }
        printf("%s\n", findWord);
        printf("Substring finded? %s\n", strcmp(str, findWord) == 0 ? "true" : "false");
    }
    else
        printf("Null pointer\n");

    
    return 0;
}