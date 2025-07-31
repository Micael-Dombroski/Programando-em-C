#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//A function returns a value
int strSize(char str[]) {
    int size = 0;
    while(str[size] != '\0') {
        size++;
    }
    return size;
}

//A procedure doesn't have a return (void)
void printChars(char str[]) {
    int i = 0;
    while(str[i] != '\0')
        printf("%c", str[i++]);
    printf("\n");
}
//procedure to convert all the string to Upper Case
void toUpr(char str[]) {
    int i = 0;
    while (str[i] != '\0') {
        str[i] = toupper(str[i]);
        i++;
    }
}
//procedure to convert all the string to Lower Case
void toLwr(char str[]) {
    int i = 0;
    while (str[i] != '\0') {
        str[i] = tolower(str[i]);
        i++;
    }
}
int main(void) {
    int size;
    size = printf("Hello World!\n");
    //printf returns the number of chars that were 
    //successfully written to the output stream
    //'\0' doesn't count
    printf("Size: %d\n", size);
    char str[] = {"Once upon a time"};
    printf("%d\n",strSize(str));
    printChars(str);
    /*
        strlwr(str);//only works on windows
        strupr(str);//only works on windows
    */
    char str2[] = {"hello world"};
    printf("Original string: %s\n", str2);
    toUpr(str2);
    printf("To Upper Case: %s\n", str2);
    toLwr(str2);
    printf("To Lower Case: %s\n", str2);
    int ret = 0;
    char c;
    do {
        printf("Define the size of the array: \n");
        ret = scanf("%d", &size);
        while((c= getchar()) != '\n');
    } while(ret != 1 && (size < 1 || size > 999));
    char scanfFormat1[10] = {"%"}, scanfFormat2[10];
    /*
        sprintf(scanfFormat2, "%d[^\n]", size); 
        //You can cause buffer overflow with this method 
        //because it doesn't control the maximum number of 
        //bytes written to the buffer
    */
    snprintf(scanfFormat2, 10, "%d[^\n]", size);
    //This method is more secure because the second argument limits 
    //how many bytes can be written to the buffer
    strcat(scanfFormat1, scanfFormat2);
    char words[size];
    printf("Write a sentence: \n");
    scanf(scanfFormat1, words);
    printf("%s\n", words);
    return 0;
}