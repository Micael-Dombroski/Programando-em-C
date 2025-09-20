#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int month, day, year;
} Date;
typedef struct {
    char name[50];
    Date date;
} Person;
typedef struct node {
    Person p;
    struct node *next;
} Node;
typedef struct {
    Node *top;
    int size;
} Stack;

void create_stack(Stack *p) {
    p -> top = NULL;
    p -> size = 0;
}
Person read_person() {
    Person p;
    printf("\nEnter the name and brithdate mm dd yyyy: \n");
    scanf("%49[^\n]%d%d%d", p.name, &p.date.month, &p.date.day, &p.date.year);
    return p;
}
void print_person(Person p) {
    printf("\nName: %s\nDate: %2d/%2d/%4d\n", p.name, p.date.month, p.date.day, p.date.year);
}
void push(Stack *p) {
    Node *new = calloc(1, sizeof(Node));
    if(new) {
        new->p = read_person();
        new->next = p -> top;
        p -> top = new;
        p -> size++;
    } else {
        printf("\n\tFailed to allocate memory...\n");
    }
}
Node* pop(Stack *stack) {
    if(stack -> top) {
        Node *remove = stack -> top;
        stack -> top = remove -> next;
        stack -> size--;
        return remove;
    } else {
        printf("\n\tStack is empty!\n");
        return NULL;
    }   
}
void print_stack(Stack *stack) {
    Node *sup = stack -> top;
    printf("\n--------------STACK Size: %d---------------\n", stack -> size);
    while(sup) {
        print_person(sup -> p);
        sup = sup -> next;
    }
    printf("\n-----------END OF STACK-----------\n");
}
int main(void) {
    Node *remove;
    Stack stack;
    create_stack(&stack);
    int opt;
    do {
        printf("\n0 - Exit\n1 - Push\n2 - Pop\n3 - Print\n");
        scanf("%d", &opt);
        while((getchar()) != '\n');
        switch (opt)
        {
        case 1:
            push(&stack);
            break;
        case 2:
            remove = pop(&stack);
            if(remove) {
                printf("\nElement removed successfully!\n");
                print_person(remove->p);
                free(remove);
            } else {
                printf("\n\tThere is no node to remove\n");
            }
            break;
        case 3: 
            print_stack(&stack);
            break;
        case 0:
            printf("\n\tExiting...\n");
            break;
        default:
        printf("\nInvalid option\n");
            break;
        }
    } while(opt != 0);
    return 0;
}