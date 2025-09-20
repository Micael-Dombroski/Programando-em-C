#include <stdio.h>
#include <stdlib.h>
#include "headers/stack.h"

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
void print_stack(Node *stack) {
    printf("\n\tSTACK\n");
    while(stack) {
        printf("\t%d\n", stack -> value);
        stack = stack -> next;
    }
    printf("\n");
}