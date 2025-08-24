#include <stdio.h>
#include <stdlib.h>
void printStr(char *arr) {
    int i = 0;
    while(*(arr + i) != '\0') {
        printf("%c", *(arr + i));
        if(*(arr+i++) == '\0')
            break;
    }
    printf("\n");
}
int strcp(char *origin, char *destiny) {
    int i =0;
    while(*(origin + i) != '\0') {
        *(destiny + i) = *(origin + i);
        i++;
    }
    *(destiny + i) = '\0';
    return i;
}
int main(void) {
    char origin[20] = "random text", destiny[20];
    printStr(&origin[0]);
    printStr(&destiny[0]);//can output memory trash 
    printf("String size: %d\n",strcp(origin, destiny));
    printStr(&origin[0]);
    printStr(&destiny[0]);
    return 0;
}