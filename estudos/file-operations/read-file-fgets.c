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
void read(char f[]) {
    FILE *file = fopen(f, "r");
    char text[500];
    if(file) {//check if the file was successfully opened
        printf("Text from the file:\n");
        while(!feof(file)) {
            //loop until fgets fails (feof is set only after 
            //an attempt to read past the end)
            if(fgets(text, 500, file)) {
                //read up to 499 characters or until newline/EOF into text
                //fgets return 0 if can't read anything
                printf("\n--> %s\n", text);
            }
        }
        fclose(file);//close the file to release resources
    } else {
        printf("\nFailed to open file!\n");
    }
}
int main(void) {
    char name[] = {"story2.txt"};
    read(name);
    return 0;
}