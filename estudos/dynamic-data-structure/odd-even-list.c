#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int value;
    struct node *next;
} Node;
typedef struct {
    Node *start;
    int size;
} List;
void create_list(List *list) {
    list -> size = 0;
    list -> start = NULL;
}
void push(List *list, int num) {
    Node *sup, *new = malloc(sizeof(Node));
    if(new) {
        new -> value = num;
        new -> next = NULL;
        if(list -> start) {
            sup = list -> start;
            while(sup -> next) {
                sup = sup -> next;
            }
            sup -> next = new;
        } else {
            list -> start = new;
        }
        list -> size++;
    } else {
        printf("\n\tFailed to allocate memory\n");
    }
}
void ordered_push(List *list, int num) {
    Node *sup, *new = malloc(sizeof(Node));
    if(new) {
        new -> value = num;
        new -> next = NULL;
        if(list -> start) {
            if(list -> start -> value > new -> value) {
                new -> next = list -> start;
                list -> start = new;
            } else {
                sup = list -> start;
                while(sup -> next && sup -> next -> value < new -> value) {
                    sup = sup -> next;
                }
                if(sup -> next) {
                    new -> next = sup -> next;
                }
                sup -> next = new;
            }
        } else {
            list -> start = new;
        }
        list -> size++;
    } else {
        printf("\n\tFailed to allocate memory\n");
    }
}
Node* pop(List *list, int num) {
    Node *sup, *remove = NULL;
    if(list -> start) {
        if(list -> start -> value == num) {
            remove = list -> start;
            list -> start = remove -> next;
            list -> size--;
        } else {
            sup = list -> start;
            while (sup -> next && sup -> next -> value != num) {
                sup = sup -> next;
            }
            if(sup -> next) {
                remove = sup -> next;
                sup -> next = remove -> next;
                list -> size--;
            }
        }
    }
    return remove;
}
Node *search(List *list, int num) {
    Node *node = NULL;
    if(list -> start) {
        node = list -> start;
        while (node && node -> value != num) {
            node = node -> next;
        }
    }
    return node;
}
void split_list(List *originList, List *evenList, List *oddList) {
    Node *sup = originList -> start;
    create_list(evenList);
    create_list(oddList);
    if(sup) {
        while(sup) {
            if(sup -> value % 2 == 0) {
                ordered_push(evenList, sup -> value);
            } else {
                ordered_push(oddList, sup -> value);
            }
            sup = sup -> next;
        }
    }
}
void print_list(List *list) {
    printf("\n\tList size: %d\n\tElements:", list -> size);
    Node *sup = list -> start;
    while(sup) {
        printf(" %d", sup -> value);
        sup = sup -> next;
    }
    if(list -> size == 0) {
        printf(" Empty...");
    }
    printf("\n\n");
}
void clear_list(List *list) {
    Node *sup, *clear;
    sup = list -> start;
    while(sup) {
        clear = pop(list, sup -> value);
        sup = clear -> next;
        free(clear);
    }
    list -> start = NULL; 
    list -> size = 0;
}
int main(void) {
    int opt, value;
    List list, oddList, evenList;
    create_list(&list);
    do {
        printf("\n\t0 - Exit\n\t1 - Insert\n\t2 - Ordered Insert\n\t3 - Remove\n\t4 - Search\n\t5 - Print\n\t6 - Split odd and even numbers\n\n");
        scanf("%d", &opt);
        switch (opt) {
        case 0:
            printf("Exiting...\n");
            break;
        case 1:
            printf("Enter an integer value: ");
            scanf("%d", &value);
            push(&list, value);
    
            break;
        case 2:
            printf("Enter an integer value: ");
            scanf("%d", &value);
            ordered_push(&list, value);
            break;
        case 3:
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
        case 4:
            printf("Enter a value to search for: ");
            scanf("%d", &value);
            Node *node = search(&list, value);
            if (node) {
                printf("The value %d was found\n", node -> value);
            } else {
                printf("\n\tThe value wasn't found\n");
            }
            break;
        case 5:
            print_list(&list);
            break;
        case 6:
            split_list(&list, &evenList, &oddList);
            printf("\n\tOriginal List\n");
            print_list(&list);
            printf("\n\tEven List\n");
            print_list(&evenList);
            printf("\n\tOdd List\n");
                print_list(&oddList);
                clear_list(&oddList);
                clear_list(&evenList);
            break;
        default:
        printf("\n\tInvalid option\n");
            break;
        }
        while((getchar()) != '\n');
    } while (opt != 0);
    return 0;
}