#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
    char word[40] = "Good morning sunshine! Box.of.Good!Good";
    /*
        strtok -> spits a string into tokens using a delimiter character
    */
    char *pt;
    pt = strtok(word, " ");
    while(pt) { //the loop continues until pt becomes NULL
        printf("Token: %s\n", pt);
        pt = strtok(NULL, "!. "); 
        //the function creates a new token whenever it finds a "!", "." or " " in the string
        /*
            After the first call to strtok, use NULL as the first argument 
            in subsequent calls. strtok keeps track of the original string 
            internally to continue tokenizing it. If you keep passing the 
            original string, strtok will keep restarting, potentially causing 
            an infinite loop.
        */
    }
    return 0;
}