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
int main (void) {
    FILE *file;
    char letter;
    file = fopen("text.txt", "w+");//create and/or open file in read and write mode("w+")
    if(file) {
        printf("Write a text and press ENTER to finish!");
        scanf("%c", &letter);//read the 1st char from user input
        while(letter != '\n'){//keep reading chars until the '\n' char
            fputc(letter, file);//write the char to the text file
            scanf("%c", &letter);//get the next char from the user input
        }
        rewind(file);//send the file pointer back to the begin of the file content
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
    return 0;
}