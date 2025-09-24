#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    char character;
    struct node *next;
} Node;
Node* push(Node *stack, char value) {
    Node *new = malloc(sizeof(Node));
    if(new) {
        new -> character = value;
        new -> next = stack;
        return new;
    } else {
        printf("\n\tFailed to allocate memory\n");
    }
    return NULL;
}
Node* pop(Node **stack) {
    Node *remove = NULL;
    if(*stack) {
        remove = *stack;
        *stack = remove -> next;
    } else {
        printf("\n\tThe stack is empty\n");
    }
    return remove;
}
void reverse_word(char x[]) {
    int i = 0;
    Node *remove, *stack = NULL;
    while(x[i] != '\0') {
        if(x[i] != ' ') {
            stack = push(stack, x[i]);
        } else {
            while(stack) {
                remove = pop(&stack);
                printf("%c", remove->character);
                free(remove);
            }
            printf(" ");
        }
        i++;
    }
    while(stack) {
        remove = pop(&stack);
        printf("%c", remove->character);
        free(remove);
    }
    printf("\n");
}
int main(void) {
    char text[50] = {"Do you wanna have a bad time?"};
    reverse_word(text);
    return 0;
}