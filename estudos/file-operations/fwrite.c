#include <stdio.h>
#include <stdlib.h>
//Write a binary file with fwrite() function
/*Open file modes
    wb -> write
    rb -> read
    ab -> attach
    rb+ -> read and write
    wb+ -> read and write (delete the content from the file if the file already exist)
    ab+ -> read and write (insert in the end of the file)
*/
typedef struct {
    char name[50];
    int day, month, year;
} Contact;

void write(char f[]) {
    Contact c;
    FILE *file = fopen(f, "ab");
    if(file) {
        printf("Enter the name and birthdate (mm dd yyyy):");
        scanf("%49[^\n]%d %d %d", c.name, &c.month, &c.day, &c.year);
        fwrite(&c, sizeof(Contact), 1, file);
        fclose(file);
    } else {
        printf("\n\tFailed to open file!\n");
    }
}

int main (void) {
    char file[] = {"contacts.dat"};
    write(file);
    return 0;
}