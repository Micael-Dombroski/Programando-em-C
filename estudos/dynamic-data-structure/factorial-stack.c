#include <stdio.h>
#include <stdlib.h>
//how to emulate the factorial recursion with stack
typedef struct  node {
    int value;
    struct node *next;
} Node;
Node* push (Node *stack, int num) {
    Node *new = malloc(sizeof(Node));
    if (new) {
        new -> value = num;
        new -> next = stack;
        return new;
    } else {
        printf("\n\tFailed to allocate memory!\n");
    }
    return NULL;
}
Node* pop (Node **stack) {
    Node *remove = NULL;
    if(*stack) {
        remove = *stack;
        *stack = remove -> next;
    } else {
        printf("\n\tThe stack is empty!\n");
    }
    return remove;
}
void print(Node *stack) {
    printf("\n\tSTACK\n");
    while(stack) {
        printf("\t%d\n", stack -> value);
        stack = stack -> next;
    }
    printf("\n");
}
int factorial(int num) {
    Node *remove, *stack = NULL;
    while(num > 1) {
        stack = push(stack, num);
        num--;
    }
    print(stack);
    while(stack) {
        remove = pop(&stack);
        num *= remove -> value;
        free(remove);
    }
    return num;
}
int main (void) {
    int value;
    printf("Enter a value greater than zero to calculate the factorial: ");
    scanf("%d", &value);
    printf("The factorial of %d is %d\n", value, factorial(value));
    return 0;
}