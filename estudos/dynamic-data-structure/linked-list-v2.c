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
    list -> start = NULL;
    list -> size = 0;
}
void push_at_start(List *list, int num) {
    Node *new = malloc(sizeof(Node));
    if(new) {
        new -> value = num;
        new -> next = list -> start;
        list -> start = new;
        list -> size++;
    } else {
        printf("\n\tFailed to allocate memory\n");
    }
}
void push_at_end(List *list, int num) {
    Node *temp, *new = malloc(sizeof(Node));
    if(new) {
        new -> value = num;
        new -> next = NULL;
        if(list -> start == NULL) {
            list -> start = new;
        } else {
            temp = list -> start;
            while(temp -> next) {
                temp = temp -> next;
            }
            temp -> next = new;
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
            new -> next = NULL;
            list -> start = new;
        } else {
            temp = list -> start;
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
        list -> size++;
    } else {
        printf("\n\tFailed to allocate memory\n");
    }
}
void print_list(List list) {
    Node *node = list.start;
    printf("\n\tList size: %d\n\tElements: ", list.size);
    while(node) {
        printf("%d ", node -> value);
        node = node -> next;
    }
    printf("\n");
}
int main(void) {
    int opt, value, prevNum;
    List list;
    create_list(&list);
    do {
        printf("\n\t0 - Exit\n\t1 - Insert at Start\n\t2 - Insert at End\n\t3 - Insert\n\t4 - Print\n\n");
        scanf("%d", &opt);
        switch (opt) {
        case 0:
            printf("Exiting....\n");
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