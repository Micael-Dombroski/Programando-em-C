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
    char name[100], c;
    int age, opt, ret = 0;
    float height;
    if(file) {//check if file was successfully opened
        do {
            do {
                printf("Enter your name, age, and height: ");
                ret = scanf("%100[^\n]%d%f", name, &age, &height);
                while((c = getchar()) != '\n');
            } while(ret != 3);
            fprintf(file, "%s %d %.2f\n", name, age, height);
            printf("Press 1 to register another person: ");
            scanf("%d", &opt);
            while((c = getchar()) != '\n');
        } while(opt == 1);
        fclose(file);
    } else {
        printf("\nFailed to open file!\n");
    }
}
int main(void) {
    char name[] = "story3.txt";
    write(name);
    return 0;
}