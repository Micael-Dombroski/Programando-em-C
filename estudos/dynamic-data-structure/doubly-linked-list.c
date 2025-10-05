#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int value;
    struct node *next;
    struct node *previous;
} Node;
void push_at_start(Node **list, int num) {
    Node *new = malloc(sizeof(Node));
    if(new) {
        new -> value = num;
        new -> next = *list;
        new -> previous = NULL;
        if(*list) {
            (*list) -> previous = new;
        }
        *list = new;
    } else {
        printf("\n\tFailed to allocate memory\n");
    }
}
void push_at_end(Node **list, int num) {
    Node *sup, *new = malloc(sizeof(Node));
    if(new) {
        new -> value = num;
        new -> next = NULL;
        new -> previous = NULL;
        if(*list) {
            sup = *list;
            while (sup -> next) {
                sup = sup -> next;
            }
            sup -> next = new;
            new -> previous = sup;
        } else {
            *list = new;
        }
    } else {
        printf("\n\tFailed to allocate memory\n");
    }
}
void push_between(Node **list, int num, int reference) {
    Node *sup, *new = malloc(sizeof(Node));
    if(new) {
        new -> value = num;
        new -> next = NULL;
        new -> previous = NULL;
        if(*list) {
            sup = *list;
            while (sup -> next && sup -> value != reference) {
                sup = sup -> next;
            }
            new -> next = sup -> next;
            sup -> next -> previous = new;
            new -> previous = sup;
            sup -> next = new;
        } else {
            *list = new;
        }
    } else {
        printf("\n\tFailed to allocate memory\n");
    }
}
void ordered_push(Node **list, int num) {
    Node *sup, *new = malloc(sizeof(Node));
    if(new) {
        new -> value = num;
        new -> next = NULL;
        new -> previous = NULL;
        if(*list == NULL) {
            *list = new;
        } else if(new -> value < (*list) -> value) {
            new -> next = *list;
            (*list) -> previous = new;
            *list = new;
        } else {
            sup = *list;
            while(sup -> next && new -> value > sup -> next -> value) {
                sup = sup -> next;
            }
            new->next = sup->next;
            if (sup->next) {
                sup->next->previous = new;
            }
            new -> previous = sup;
            sup -> next = new;
        }
    } else {
        printf("\n\tFailed to allocate memory\n");
    }
}
Node* pop(Node **list, int value) {
    Node *sup, *remove = NULL;
    if(*list) {
        if((*list) -> value == value) {
            remove = *list;
            *list = remove -> next;
            if(*list) {
                (*list) -> previous = NULL;
            }
        } else {
            sup = *list;
            while(sup -> next && sup -> next -> value != value) {
                sup = sup -> next;
            }
            if(sup -> next) {
                remove = sup -> next;
                sup -> next = remove -> next;
                if(sup -> next) {
                    sup -> next -> previous = sup;
                }
            }
        }
    } else {
        printf("\n\tList is empty\n");
    }
    return remove;
}
Node* search(Node **list, int value) {
    Node *sup, *node = NULL;
    if(*list) {
        sup = *list;
        while (sup && sup -> value != value) {
            sup = sup -> next;
        }
        node = sup;
    } else {
        printf("\n\tList is empty\n");
    }
    return node;
}
void print_list(Node **list) {
    Node *sup = *list;
    printf("\n\tList values:");
    while(sup) {
        printf(" %d", sup -> value);
        sup = sup -> next;
    }
    printf("\n");
}
Node* last_node(Node **list) {
    Node *last = *list;
    if(last) {
        while(last -> next) {
            last = last -> next;
        }
    }
    return last;
}
void print_list_reverse(Node *list) {
    Node *sup = list;
    printf("\nReverse List:");
    while(sup) {
        printf(" %d", sup -> value);
        sup = sup -> previous;
    }
    printf("\n");
}
int main(void) {
    int opt, value, prevNum;
    Node *list = NULL;
    do {
        printf("\n\t0 - Exit\n\t1 - Insert at Start\n\t2 - Insert at End\n\t3 - Insert\n\t4 - Ordered Insertion\n\t5 - Remove\n\t6 - Search\n\t7 - Print\n\t8 - Print Reverse\n\n");
        scanf("%d", &opt);
        switch (opt) {
        case 0:
            printf("Exiting...\n");
            break;
        case 1:
            printf("Enter an integer value: ");
            scanf("%d", &value);
            push_at_start(&list, value);
            break;
        case 2:
            printf("Enter an integer value: ");
            scanf("%d", &value);
            push_at_end(&list, value);
            break;
        case 3:
            printf("Enter an integer value: ");
            scanf("%d", &value);
            printf("Enter the reference value: ");
            scanf("%d", &prevNum);
            push_between(&list, value, prevNum);
            break;
        case 4:
            printf("Enter an integer value: ");
            scanf("%d", &value);
            ordered_push(&list, value);
            break;
        case 5:
            printf("Enter a value to remove: ");
            scanf("%d", &value);
            Node *remove = pop(&list, value);
            if(remove) {
                printf("The value %d was removed\n", remove -> value);
                free(remove);
            } else {
                printf("\n\tThe value doesn't exist in the list\n");
            }
            break;
        case 6:
            printf("Enter a value to search for: ");
            scanf("%d", &value);
            Node *node = search(&list, value);
            if (node) {
                printf("The value %d was found\n", node -> value);
            } else {
                printf("\n\tThe value wasn't found\n");
            }
            break;
        case 7:
            print_list(&list);
            break;
        case 8:
            print_list_reverse(last_node(&list));
            break;
        default:
        printf("\n\tInvalid option\n");
            break;
        }
        while((getchar()) != '\n');
    } while (opt != 0);

    return EXIT_SUCCESS;
}