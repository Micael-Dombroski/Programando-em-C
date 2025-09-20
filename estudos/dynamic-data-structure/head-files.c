#include <stdio.h>
#include <stdlib.h>
#include "headers/stack.h"
//how to emulate the factorial recursion with stack
int factorial(int num) {
    Node *remove, *stack = NULL;

    while (num > 1) {
        stack = push(stack, num);
        num--;
    }

    print_stack(stack);

    while (stack) {
        remove = pop(&stack);
        num *= remove->value;
        free(remove);
    }

    return num;
}
int main(void) {
    int n = 5;
    printf("Factorial of %d = %d\n", n, factorial(n));
    getchar();
    return 0;
}