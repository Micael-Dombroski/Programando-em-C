#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int value;
    struct node *next;
} Node;
typedef struct {
    Node *first;
    Node *last;
    int size;
} Queue;
void create_queue(Queue *queue) {
    queue -> first = NULL;
    queue -> last = NULL;
    queue -> size = 0;
}
void insert_in_queue(Queue *queue, int num) {
    Node *new = malloc(sizeof(Node));
    new -> value = num;
    new -> next = NULL;
    if(new) {
        if(queue -> first == NULL) {
            queue -> first = new;
            queue -> last = new;
        } else {
            queue -> last -> next = new;
            queue -> last = new;
        }
        queue -> size++;
    } else {
        printf("\n\tFailed to allocate memory\n");
    }
    printf("\tCurrent queue size: %d\n", queue -> size);
}
Node *remove_from_queue(Queue *queue) {
    Node *remove = NULL;
    if(queue -> first) {
        remove = queue -> first;
        if(remove) {
            queue -> first = remove -> next;
            queue -> size--;
        } else {
            queue -> last = NULL;
        }
    } else {
        printf("\n\tQueue is empty\n");
    }
    printf("\tCurrent queue size: %d\n", queue -> size);
    return remove;
}
void print_queue(Queue *queue) {
    Node *temp = queue -> first;
    printf("\n\t---QUEUE SIZE: %d---\n\t", queue -> size);
    while(temp != NULL) {
        printf("%d ", temp->value);
        temp = temp -> next;
    }
    printf("\n\t----END OF QUEUE----\n");
}
int main(void) {
    Node *r;
    Queue queue;
    int opt, value;
    create_queue(&queue);
    do {
        printf("\t0 - Exit\n\t1 - Insert\n\t2 - Remove\n\t3 - Print\n");
        scanf("%d", &opt);
        while((getchar()) != '\n');
        switch (opt)
        {
            case 0:
                printf("\n\tExiting...\n");
                break;
            case 1:
                printf("Enter an Integer value: \n");
                scanf("%d", &value);
                insert_in_queue(&queue, value);
                while((getchar()) != '\n');
                break;
            case 2:
                r = remove_from_queue(&queue);
                if(r) {
                    printf("Removed value: %d\n", r -> value);
                }
                break;
            case 3:
                print_queue(&queue);
                break;
            default:
                printf("\n\tInvalid option\n");
                break;
        }
    } while(opt != 0);
    return 0;
}