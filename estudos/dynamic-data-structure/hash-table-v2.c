#include <stdio.h>
#include <stdlib.h>
#define SIZE 29

typedef struct node {
    int key;
    struct node *next;
} Node;
typedef struct {
    Node *start;
    int size;
} List;
void initializeList(List *l) {
    l -> start = NULL;
    l -> size = 0;
}
void insert_in_list(List *l, int value) {
    Node *new = malloc(sizeof(Node));
    if(!new) {
        printf("\n\tFailed to allocate memory\n");
        return;
    }
    new -> key = value;
    new -> next = NULL;
    if(l -> start == NULL) {
        l -> start = new;
    } else {
        Node *sup = l -> start;
        while (sup -> next != NULL) {
            sup = sup -> next;
        }
        sup -> next = new;
    }
    l -> size++;
}
int search_in_list(List *l, int value) {
    Node *sup = l -> start;
    while(sup && sup -> key != value) {
        sup = sup -> next;
    }
    if(sup) {
        return sup -> key;
    }
    printf("\n\tValue not found\n");
    return 0;
}
void print_list(List *l) {
    Node *sup = l -> start;
    printf(" Size: %d > ", l -> size);
    while (sup) {
        printf("%d ", sup -> key);
        sup = sup -> next;
    }
    printf("\n");
}

void initializeTable(List t[]) {
    for (int i = 0; i < SIZE; i++) {
        initializeList(&t[i]);
    }
}
int hashFunction(int key) {
    return key % SIZE;
}
void insert(List t[], int value) {
    int id = hashFunction(value);
    insert_in_list(&t[id], value);
}
int search(List t[], int key) {
    int id = hashFunction(key);
    printf("\nGenerated index: %d\n", id);
    return search_in_list(&t[id], key);
}
void print(List t[]) {
    for(int i = 0; i < SIZE; i++) {
        printf("%2d =", i);
        print_list(&t[i]);
    }
    printf("\n");
}
int main(void) {
    List table[SIZE];
    initializeTable(table);
    int opt, value;
    do {
        printf("HashTable Menu\n");
        printf("\t0 - Exit\n\t1 - Insert\n\t2 - Search\n\t3 - Print\n");
        printf("Choose an option: ");
        scanf("%d", &opt);
        while((getchar()) != '\n');
        switch (opt) {
        case 0:
           printf("\n\tExiting...\n");
            break;
        case 1:
            printf("Which value you want to insert? ");
            scanf("%d", &value);
            while((getchar()) != '\n');
            insert(table, value);
            break;
        case 2:
            printf("Which value you want to search for? ");
            scanf("%d", &value);
            while((getchar()) != '\n');
            int returnValue = search(table, value);
            if(returnValue) {
                printf("\nThe value %d was found\n", returnValue);
            } else {
                printf("\n\tThe value wasn't found\n");
            }
            break;
        case 3:
            print(table);
            break;
        default:
        printf("\n\tInvalid option!\n");
            break;
        }
    } while (opt != 0);
    return EXIT_SUCCESS;
}