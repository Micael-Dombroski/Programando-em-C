#include <stdio.h>
#include <stdlib.h>
/*
    Normal expression: 3 * [(5 - 2) / 5]
    Poorly expression: 3 * [(5 - 2) / 5
*/
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
void print_stack(Node *stack) {
    printf("\n\tSTACK\n");
    while(stack) {
        printf("\t%c\n", stack -> character);
        stack = stack -> next;
    }
    printf("\tEND OF STACK\n\n");
}
int is_pair(char endChar, char popChar) {
    if(endChar == ']' && popChar == '[') {
        return 1;
    }
    if(endChar == '}' && popChar == '{') {
        return 1;
    }
    if(endChar == ')' && popChar == '(') {
        return 1;
    }
    return 0;
}
int indentify_formation(char x[]) {
    int i = 0;
    Node *remove, *stack = NULL;
    while(x[i] != '\0') {
        if(x[i] == '[' || x[i] == '{' || x[i] == '(') {
            stack = push(stack, x[i]);
            print_stack(stack);
        } else if(x[i] == ']' || x[i] == '}' || x[i] == ')') {
            remove = pop(&stack);
            if(is_pair(x[i], remove -> character == 0)) {
                printf("\n\tExXPRESSION POORLY FORMED\n");
                return 1; //poorly formed
            }
            free(remove);
        }
        i++;
    }
    print_stack(stack);
    if(stack) {
        printf("\n\tExpression poorly formed\n");
        return 1; //poorly formed
    } else {
        printf("\n\tWELL-FORMED EXPRESSION\n");
        return 0;
    }
}
int main (void) {
    char exp[50];
    printf("Enter an expression: ");
    scanf("%49[^\n]", exp);
    printf("\nExpression: %s\nReturn: %d\n", exp, indentify_formation(exp));

    return 0;
}