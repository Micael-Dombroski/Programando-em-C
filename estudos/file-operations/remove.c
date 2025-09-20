#include <stdio.h>
#include <stdlib.h>
void create_file(char f[]) {
    FILE *file = fopen(f, "w");
    if(file) {
        fprintf(file, "Testing remove file function...");
        fclose(file);
    } else {
        printf("\n\tFailed to create file\n");
    }
}
void remove_file(char f[]) {
    FILE *file = fopen(f, "r");
    if(file) {
        printf("\n\tFile opened successfully\n");
        fclose(file);
        int ret = remove(f);
        printf("File removed successfully!\n");
        printf("\nRemove return: %d\n", ret);
        //remove function return 0 if it can remove the file
    } else {
        printf("\n\tFile doesn't exist\n");
        printf("\nRemove return: %d\n", remove(f));//remove return -1 if it can't remove file
    }
}
int main(void) {
    char name[] = {"removeFile.txt"};
    //File doesn't exist
    remove_file(name);
    //Creating file
    create_file(name);
    //Deleting file
    remove_file(name);
    //File doesn't exist
    remove_file(name);

    return 0;
}