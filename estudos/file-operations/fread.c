#include <stdio.h>
#include <stdlib.h>
//Read a binary file with fwrite() function
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

void read(char f[]) {
    Contact c;
    FILE *file = fopen(f, "rb");
    if(file) {
        while(!feof(file)) {
            if(fread(&c, sizeof(Contact), 1, file)) {
                printf("\nName: %s\nBirthdate: %d/%d/%d\n", c.name, c.month, c.day, c.year);
            }
        }
        fclose(file);
    } else {
        printf("\n\tFailed to open file!\n");
    }
}

int main(void) {
    char file[] = {"contacts.dat"};
    read(file);
    return 0;
}