#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void reverse(char *name) {
    int end = strlen(name) - 1, i = 0;
    while(end > i) {
        char copy = *(name + i);
        *(name + i) = *(name + end);
        *(name + end) = copy;
        i ++;
        end--;
    }
}
char *reverseName(char *name) {
    int end = strlen(name) - 1, size = strlen(name);
    char *reverse;
    reverse = calloc(size, sizeof(char));
    for(int i = 0; i < size; i++) {
        *(reverse + i) = *(name + end);
        end--;
    }
    *(reverse + size) = '\0';
    return reverse;
}
int main(void) {
    int size = 20;
    char *name;
    name = calloc(size, sizeof(char));
    printf("Write a name: ");
    fgets(name, size, stdin);
    for (int i = 0; i < size; i++) {
        if(*(name + i) == '\n')
            *(name + i) = '\0';
        if(*(name + i) == '\0')
            break;
    }
    printf("Name: %s\n", name);
    //reverse(name);
    //printf("Reverse: %s\n", name);
    char *reverse;
    reverse = reverseName(name);
    printf("Reverse: %s\n", reverse);
    free(name);
    free(reverse);
    name = NULL;
    reverse = NULL;
    return 0;
}