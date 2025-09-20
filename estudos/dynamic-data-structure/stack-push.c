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
Person read_person() {
    Person p;
    printf("\nEnter the name and brithdate mm dd yyyy: \n");
    scanf("%49[^\n]%d%d%d", p.name, &p.date.month, &p.date.day, &p.date.year);
    return p;
}
void print_person(Person p) {
    printf("\nName: %s\nDate: %2d/%2d/%4d\n", p.name, p.date.month, p.date.day, p.date.year);
}
Node* push(Node *top) {
    Node *new = calloc(sizeof(Node), 1);
    if(new) {
        new->p = read_person();
        new->next = top;
        return new;
    } else {
        printf("\n\tFailed to allocate memory...\n");
        return NULL;
    }
}
Node* pop(Node **top) {
    if(*top == NULL) {
        printf("\n\tStack is empty!\n");
        return NULL;
    }
    Node *remove = *top;
    *top = remove->next;
    return remove;
}
void print_stack(Node *top) {
    printf("\n--------------STACK---------------\n");
    while(top) {
        print_person(top->p);
        top = top->next;
    }
    printf("\n-----------END OF STACK-----------\n");
}
int main(void) {
    Node *remove, *top = NULL;
    int opt;
    do {
        printf("\n0 - Exit\n1 - Push\n2 - Pop\n3 - Print\n");
        scanf("%d", &opt);
        while((getchar()) != '\n');
        switch (opt)
        {
        case 1:
            top = push(top);
            break;
        case 2:
            remove = pop(&top);
            if(remove) {
                printf("\nElement removed successfully!\n");
                print_person(remove->p);
            } else {
                printf("\n\tThere is no node to remove\n");
            }
            break;
        case 3: 
            print_stack(top);
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