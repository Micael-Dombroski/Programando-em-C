#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int value;
    struct node *next;
} Node;

void push_at_start(Node **list, int num) {
    Node *new = malloc(sizeof(Node));
    if(new) {
        new -> value = num;
        new -> next = *list;
        *list = new;
    } else {
        printf("\n\tFailed to allocate memory\n");
    }
}
void push_at_end(Node **list, int num) {
    Node *temp, *new = malloc(sizeof(Node));
    if(new) {
        new -> value = num;
        new -> next = NULL;
        if(*list == NULL) {
            *list = new;
        } else {
            temp = *list;
            while(temp -> next) {
                temp = temp -> next;
            }
            temp -> next = new;
        }
        
    } else {
        printf("\n\tFailed to allocate memory\n");
    }
}
void push_between(Node **list, int num, int prev) {
    Node *temp, *new = malloc(sizeof(Node));
    if(new) {
        new -> value = num;
        if(*list == NULL) {
            new -> next = NULL;
            *list = new;
        } else {
            temp = *list;
            while(temp -> value != prev && temp -> next) {
                temp = temp -> next;
            }
            if(!temp -> next) {
                temp -> next = new;
            } else {
                new -> next = temp -> next;
                temp -> next = new;
            }
        }
    } else {
        printf("\n\tFailed to allocate memory\n");
    }
}
void ordered_push(Node **list, int num) {
    Node *sup, *new = malloc(sizeof(Node));
    if(new) {
        new -> value = num;
        if(*list == NULL) {
            new -> next = NULL;
            *list = new;
        } else if(new -> value < (*list) -> value) {
            new -> next = *list;
            *list = new;
        } else {
            sup = *list;
            while(sup -> next && new -> value > sup -> next -> value) {
                sup = sup -> next;
            }
            new -> next = sup -> next;
            sup -> next = new;
        }
    } else {
        printf("\n\tFailed to allocate memory\n");
    }
}
Node* pop(Node **list, int num) {
    Node *sup, *remove = NULL;
    if(*list) {
        if((*list) -> value == num) {
            remove = *list;
            *list = remove -> next;
        } else {
            sup = *list;
            while(sup -> next && sup -> next -> value != num) {
                sup = sup -> next;
            }
            if(sup -> next) {
                remove = sup -> next;
                sup -> next = remove -> next;
            }
        }
    }

    return remove;
}
void print_list(Node *node) {
    printf("\n\tList: ");
    while(node) {
        printf("%d ", node -> value);
        node = node -> next;
    }
    printf("\n");
}
int main(void) {
    int opt, value, prevNum;
    Node *list = NULL;
    do {
        printf("\n\t0 - Exit\n\t1 - Insert at Start\n\t2 - Insert at End\n\t3 - Insert\n\t4 - Ordered Insertion\n\t5 - Remove\n\t6 - Print\n\n");
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
            print_list(list);
            break;
        default:
        printf("\n\tInvalid option\n");
            break;
        }
        while((getchar()) != '\n');
    } while (opt != 0);

    return 0;
}