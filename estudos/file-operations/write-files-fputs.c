#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
    File opening modes
    w -> write
    r -> read
    a -> append
    r+ -> read and write
    w+ -> read and write (clean the content if the file already exists)
    a+ -> read and write (writes at the end of the file)
*/
void write(char f[]) {
    FILE *file = fopen(f, "a+");
    char text [500], c;
    if(file) {
        printf("Enter a phrase or 1 char to close the program: \n");
        do {
            scanf("%500[^\n]", text);//write the content from text to the file
            if(strlen(text) != 1) {
                fputs(text, file);
                fputc('\n', file);
            }
            while((c = getchar()) != '\n');  
        } while (strlen(text) != 1);
        fclose(file);
    } else {
        printf("\nFailed to open file!\n");
    }
}
int main(void) {
    char name[] = {"story2.txt"};
    write(name);
    return 0;
}