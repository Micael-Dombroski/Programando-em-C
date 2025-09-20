#ifndef STACK_H_INCLUDED //if not defined
#define STACK_H_INCLUDED

typedef struct  node {
    int value;
    struct node *next;
} Node;
Node* push (Node *stack, int num) ;
Node* pop (Node **stack);
void print_stack(Node *stack);

#endif // STACK_H_INCLUDED