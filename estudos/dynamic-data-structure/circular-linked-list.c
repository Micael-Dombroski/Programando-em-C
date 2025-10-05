#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int value;
    struct node *next;
} Node;
typedef struct {
    Node *start;
    Node *end;
    int size;
} List;
void create_list(List *list) {
    list -> start = NULL;
    list -> end = NULL;
    list -> size = 0;
}
void push_at_start(List *list, int num) {
    Node *new = malloc(sizeof(Node));
    if(new) {
        new -> value = num;
        new -> next = list -> start;
        list -> start = new;
        if(!list -> end) {
            list -> end = new;
        }
        list -> end -> next = list -> start;
        list -> size++;
    } else {
        printf("\n\tFailed to allocate memory\n");
    }
}
void push_at_end(List *list, int num) {
    Node *new = malloc(sizeof(Node));
    if(new) {
        new -> value = num;
        if(list -> start == NULL) {
            list -> start = new;
            list -> end = new;
            list -> end -> next = list -> start;
        } else {
            list -> end -> next = new;
            list -> end = new;
            list -> end -> next = list -> start;
        }
        list -> size++;
    } else {
        printf("\n\tFailed to allocate memory\n");
    }
}
void push_between(List *list, int num, int prev) {
    Node *temp, *new = malloc(sizeof(Node));
    if(new) {
        new -> value = num;
        if(list -> start == NULL) {
            push_at_start(list, num);
        } else {
            temp = list -> start;
            while(temp -> value != prev && temp -> next != list -> start) {
                temp = temp -> next;
            }
            if(temp -> next == list -> start) {
                push_at_end(list, num);
            } else {
                new -> next = temp -> next;
                temp -> next = new;
                list -> size++;
            }
        }
    } else {
        printf("\n\tFailed to allocate memory\n");
    }
}
void ordered_push(List *list, int num) {
    Node *sup, *new = malloc(sizeof(Node));
    if(new) {
        new -> value = num;
        if(list -> start == NULL) {
            push_at_start(list, num);
        } else if(new -> value < list -> start -> value) {
            push_at_start(list, num);
        } else {
            sup = list -> start;
            while(sup -> next != list -> start && new -> value > sup -> next -> value) {
                sup = sup -> next;
            }
            if(sup -> next == list -> start) {
                push_at_end(list, num);
            } else {
                new -> next = sup -> next;
                sup -> next = new;
                list -> size++;
            }
        }
    } else {
        printf("\n\tFailed to allocate memory\n");
    }
}
Node* pop(List *list, int num) {
    Node *sup, *remove = NULL;
    if(list -> start) {
        if(list -> start -> value == num) {
            remove = list -> start;
            if(list -> start == list -> end) {
                list -> start = NULL;
                list -> end = NULL;
            } else {
                remove = list -> start;
                list -> start = remove -> next;
                list -> end -> next = list -> start;
            }
            list -> size--;
        } else {
            sup = list -> start;
            while(sup -> next != list -> start && sup -> next -> value != num) {
                sup = sup -> next;
            }
            if(sup -> next -> value == num) {
                if(sup -> next == list -> end) {
                    remove = sup -> next;
                    list -> end = sup;
                    list -> end -> next = list -> start;
                } else {
                    remove = sup -> next;
                    sup -> next = remove -> next;
                }
                list -> size--;
            }
        }
    } else  {
        printf("\n\tList is empty\n");
    }
    return remove;
}
Node* search(List *list, int num) {
    Node *sup = list -> start;
    if(sup) {
        do {
            if(sup -> value == num) {
                return sup;
            }
            sup = sup -> next;
        } while(sup -> next != list -> start);
    }
    return NULL;
}
void print_list(List list) {
    Node *node = list.start;
    printf("\n\tList size: %d\n\tElements: ", list.size);
    if(node) {
        do {
            printf("%d ", node -> value);
            node = node -> next;
        } while(node != list.start);
        printf("\nStart element: %d\n", node -> value);
    }
    printf("\n\n");
}
int main(void) {
    int opt, value, prevNum;
    List list;
    create_list(&list);
    do {
        printf("\n\t0 - Exit\n\t1 - Insert at Start\n\t2 - Insert at End\n\t3 - Insert\n\t4 - Ordered Insertion\n\t5 - Remove\n\t6 - Search\n\t7 - Print\n\n");
        scanf("%d", &opt);
        switch (opt) {
        case 0:
            printf("\n\tExiting...\n");
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