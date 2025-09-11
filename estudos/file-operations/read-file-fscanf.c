#include <stdio.h>
#include <stdlib.h>
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
    if(file) {
        printf("Read data from file\n");
        char name[100];
        int age;
        float height;
        while(fscanf(file, "%s%d%f", name, &age, &height) != -1) {
            //fscanf return -1 if it can read data from file (eof)
            printf("\nName: %s\nAge: %d\nHeight: %.2f\n", name, age, height);
        };
    } else {
        printf("\n\tFailed to open file\n");
    }
}
int main(void) {
    char fileName[] = {"story3.txt"};
    read(fileName);
    return 0;
}