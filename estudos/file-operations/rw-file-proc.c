#include <stdio.h>
#include <stdlib.h>
//how to write a text file with fputc function?
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
    FILE *file;
    char letter;
    file = fopen(f, "w");//create and/or open file in write mode("w")
    if(file) {
        printf("Write a text and press ENTER to finish!\n");
        scanf("%c", &letter);//read the 1st char from user input
        while(letter != '\n') {//keep reading chars until the '\n' char
            fputc(letter, file);//write the char to the text file
            scanf("%c", &letter);//get the next char from the user input
        }
        fclose(file);
    } else {
        printf("\n\t--> Failed to open file!\n");
    }
}
void read(char f[]) {
    FILE *file;
    char letter;
    file = fopen(f, "r");//create and/or open file in read mode("r")
    if(file) {
        printf("\n\tReading the content from file\n");
        while(!feof(file)) {
        //feof = find end of file = return true if it reaches into the end
            letter = fgetc(file);
            //get the current char pointed by file pointer and send 
            //the pointer to the next position
            printf("%c", letter);
        }
        fclose(file);//close the file
    } else {
        printf("\n\t--> Failed to open file!\n");
    }
}
int main (void) {
    char fileName[30], c;
    printf("Write the file name that you want to open in the current directory: \n");
    scanf("%30[^\n]", fileName);
    while((c = getchar()) != '\n');
    write(fileName);
    read(fileName);
    return 0;
}