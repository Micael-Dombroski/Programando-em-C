#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
    char names[5][25];
    for(int i = 0; i< 5; i++) {
        printf("Insert the name in position %d: ", i);
        fgets(names[i], 25, stdin);
        /*
        scanf("%25[^\n]", names[i]); //read the string until a newline char('\n')
        scanf("%c"); removes the leftover '\n' from the input buffer
        */
    }
    for (int i = 0; i < 5; i++) {
        int j = 0;
        while(names[i][j] != '\n') {
            j++;
        }
        names[i][j] = '\0'; //removing '\n' from the string
    }
        
    for (int i = 0; i < 5; i++)
        printf("Name %d: %s\n", i, names[i]);
    

    return 0;
}