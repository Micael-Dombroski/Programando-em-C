#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void word_triangle(char *c) {
    int size = strlen(c);
    char *last = (c + size -1);
    for (int i = 1; i <= size; i++)
    {
        for(int j = size - i; j > 0; j--)
            printf(" ");
        int pos = i - 1;
        while(pos > 0)//left side
            printf("%c",  *(last - pos--));
        while(pos < i)//right side
            printf("%c",  *(last - pos++));
        printf("\n");
    }
}

int main(void) {
    char word[50];
    printf("Enter a word: ");
    scanf("%49[^\n]", word);
    printf("\n");
    word_triangle(word);
    return EXIT_SUCCESS;
}