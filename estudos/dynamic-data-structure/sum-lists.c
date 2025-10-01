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
void copy_list(List *originList, List *destinyList) {
    Node *sup = originList -> start;
    if(sup) {
        while(sup) {
            push(destinyList, sup -> value);
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
List* choose_list2(List *list1, List *list2) {
    printf("Which list you want to use: (1) list A, (2) list B\n");
    int opt = 0;
    scanf("%d", &opt);
    switch (opt)
    {
    case 1:
        return list1;
        break;
    case 2:
        return list2;
        break;
    default:
        printf("\n\tInvalid option\n");
        break;
    }
    return NULL;
}
List* choose_list3(List *list1, List *list2, List *list3) {
    printf("Which list you want to use: (1) list A, (2) list B, (3) list C\n");
    int opt = 0;
    scanf("%d", &opt);
    switch (opt)
    {
    case 1:
        return list1;
        break;
    case 2:
        return list2;
        break;
    case 3:
        return list3;
        break;
    default:
        printf("\n\tInvalid option\n");
        break;
    }
    return NULL;
}
int main(void) {
    int opt, value;
    List aList, bList, cList, *list = NULL;
    create_list(&aList);
    create_list(&bList);
    create_list(&cList);
    do {
        printf("\n\t0 - Exit\n\t1 - Insert\n\t2 - Ordered Insert\n\t3 - Remove\n\t4 - Search\n\t5 - Print\n\t6 - Copy\n\n");
        scanf("%d", &opt);
        switch (opt) {
        case 0:
            printf("Exiting...\n");
            break;
        case 1:
            list = choose_list2(&aList, &bList);
            if(list) {
                printf("Enter an integer value: ");
                scanf("%d", &value);
                push(list, value);
            }
            break;
        case 2:
            list = choose_list2(&aList, &bList);
            if(list) {
                printf("Enter an integer value: ");
                scanf("%d", &value);
                ordered_push(list, value);
            }
            break;
        case 3:
            list = choose_list3(&aList, &bList, &cList);
            if(list) {
                printf("Enter a value to remove: ");
                scanf("%d", &value);
                Node *remove = pop(list, value);
                if(remove) {
                    printf("The value %d was removed\n", remove -> value);
                    free(remove);
                } else {
                    printf("\n\tThe value doesn't exist in the list\n");
                }
            }
            break;
        case 4:
            list = choose_list2(&aList, &bList);
            if(!list) {
                printf("Enter a value to search for: ");
                scanf("%d", &value);
                Node *node = search(list, value);
                if (node) {
                    printf("The value %d was found\n", node -> value);
                } else {
                    printf("\n\tThe value wasn't found\n");
                }
            }
            break;
        case 5:
            list = choose_list3(&aList, &bList, &cList);
            if(list) {
                print_list(list);
            }
            break;
        case 6:
            copy_list(&aList, &cList);
            copy_list(&bList, &cList);
            printf("\nList A\n");
            print_list(&aList);
            printf("\nList B\n");
            print_list(&bList);
            printf("\nList C\n");
            print_list(&cList);
            break;
        default:
        printf("\n\tInvalid option\n");
            break;
        }
        while((getchar()) != '\n');
    } while (opt != 0);
    return 0;
}