#include <stdio.h>
#include <stdlib.h>
//FIFO
typedef struct node
{
    int value;
    struct node *next;
} Node;
void insert_in_queue(Node **queue, int num) {
    Node *temp, *new = malloc(sizeof(Node));
    if (new) {
        new -> value = num;
        new -> next = NULL;
        if(*queue == NULL) {
            *queue = new;
        } else {
            temp = *queue;
            while(temp -> next) {
                temp = temp -> next;
            }
            temp -> next = new;
        }
    } else {
        printf("\n\tFailed to allocate memory\n");
    }
}
void insert_with_priority_in_queue(Node **queue, int num) {
    Node *temp, *new = malloc(sizeof(Node));
    if (new) {
        new -> value = num;
        new -> next = NULL;
        if(*queue == NULL) {
            *queue = new;
        } else {
            if (num > 59) {
                if((*queue) -> value < 60) {
                    new -> next = *queue;
                    *queue = new;
                } else {
                    temp = *queue;
                    while (temp -> next && temp -> next -> value > 59) {
                        temp = temp -> next;
                    }
                    new -> next = temp -> next;
                    temp -> next = new;
                }
            } else {
                temp = *queue;
                while(temp -> next) {
                    temp = temp -> next;
                }
                temp -> next = new;
            }
        }
    } else {
        printf("\n\tFailed to allocate memory\n");
    }
}
Node* remove_from_queue(Node **queue) {
    Node *remove = NULL;
    if(*queue) {
        remove = *queue;
        *queue = remove -> next;
    } else {
        printf("\n\tQueue is empty\n\n");
    }
    return remove;
}
void print_queue(Node *queue) {
    printf("\n\t-------QUEUE-------\n\t");
    while(queue) {
        printf("%d ", queue->value);
        queue = queue -> next;
    }
    printf("\n\t----END OF QUEUE----\n");
}
int main(void) {
    Node *r, *queue = NULL;
    int opt = 0, value;
    do {
        printf("\t0 - Exit\n\t1 - Insert\n\t2 - Remove\n\t3 - Print\n\t4 - Insert with priority\n");
        scanf("%d", &opt);
        switch (opt)
        {
        case 0:
            printf("Exiting...\n");
            break;
        case 1:
            printf("Enter an Integer value: \n");
            scanf("%d", &value);
            insert_in_queue(&queue, value);
            break;
        case 2:
            r = remove_from_queue(&queue);
            if(r) {
                printf("Removed value: %d\n", r->value);
            }
            break;
        case 3:
            print_queue(queue);
            break;
        case 4:
            printf("Enter an Integer value: \n");
            scanf("%d", &value);
            insert_with_priority_in_queue(&queue, value);
            break;
        default:
        printf("\n\tInvalid option\n");
            break;
        }
    } while(opt != 0);
    return 0;
}