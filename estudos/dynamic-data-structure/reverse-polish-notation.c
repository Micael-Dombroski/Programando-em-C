#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node {
    float value;
    struct node *next;
} Node;
Node* push (Node *stack, float num) {
    Node *new = malloc(sizeof(Node));
    if(new) {
        new->value = num;
        new->next = stack;
        return new;
    } else {
        printf("\n\tFailed to allocate memory\n");
    }
    return NULL;
}
Node* pop (Node **stack) {
    Node *remove = NULL;
    if(*stack) {
        remove = *stack;
        *stack = remove->next;
    } else {
        printf("\n\tThe stack is empty\n");
    }
    return remove;
}
float operation(float a, float b, char x) {
    switch (x)
    {
    case '+':
        return a + b;
        break;
    case '-':
        return a - b;
        break;
    case '/':
        return a / b;
        break;
    case '*':
        return a * b;
        break;
    default:
        return 0.0;
        break;
    }
}
float solve_expression(char x[]) {
    char *pt;
    float num;
    Node *n1, *n2, *stack = NULL;
    pt = strtok(x, " ");
    while (pt) {
        if(pt[0] == '+' || pt[0] == '-' || pt[0] == '/' || pt[0] == '*') {
            n2 = pop(&stack);
            n1 = pop(&stack);
            num = operation(n1->value, n2->value, pt[0]);
            stack = push(stack, num);
            free(n1);
            free(n2);
        } else {
            num = strtol(pt, NULL, 10);
            stack = push(stack, num);
        }
        pt = strtok(NULL, " ");
    }
    n1 = pop(&stack);
    num = n1->value;
    free(n1);
    return num;
}

int main(void) {
    char expression[50] = {"5 2 3 + * 4 / 6 -"};
    printf("%s = %.2f\n", expression, solve_expression(expression));
    return 0;
}