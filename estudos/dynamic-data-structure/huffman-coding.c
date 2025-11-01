#include <stdio.h>
#include <stdlib.h>
/*
    Huffman coding is a lossless data compression technique, 
    no information is lost when compressing and decompressing 
    a file.

    Often used to compress text files.

    Typically uses tables, linked-list or queue and binary 
    tree to compress.
*/

#define SIZE 256

typedef struct node {
    unsigned char c;
    unsigned int frequency;
    struct node *left, *right, *next;
} Node;

typedef struct {
    Node *start;
    int size;
} List;

void initialize_table_with_zero(unsigned int tab[]) {
    for(int i = 0; i < SIZE; i++) {
        tab[i] = 0;
    }
}

void fill_frequency_tab(unsigned char text[], unsigned int tab[]) {
    int i = 0;
    while(text[i] != '\0') {
        tab[text[i++]]++;
    }
}

void print_frequency_tab(unsigned int tab[]) {
    for(int i = 0; i < SIZE; i++) {
        if(tab[i] > 0) {
            printf("\t%3d = %u = %c\n", i, tab[i], i);
        }
    }
}

void create_list(List *list) {
    list -> start = NULL;
    list -> size = 0;
}

void ordered_insert(List *list, Node *node) {
    if(list -> start) {
        if(list -> start -> frequency > node -> frequency) {
            node -> next = list -> start;
            list -> start = node;
        } else {
            Node *sup = list -> start;
            while(sup -> next && sup -> next -> frequency <= node -> frequency) {
                sup = sup -> next;
            }
            node -> next = sup -> next;
            sup -> next = node;
        }
    } else {
        list -> start = node;
    }
    list -> size++;
}

void fill_list(unsigned int tab[], List *list) {
    for(int i = 0; i< SIZE; i++) {
        if(tab[i] > 0) {
            Node *new = malloc(sizeof(Node));
            if(new) {
                new -> c = i;
                new -> frequency = tab[i];
                new -> next = NULL;
                new -> left = NULL;
                new -> right = NULL;
                ordered_insert(list, new);
            } else {
                printf("\tFailed to allocate memory in fill_list\n");
                break;
            }
        }
    }
}

void print_list(List *list) {
    if(list -> start) {
        Node *sup = list -> start;
        printf("\n\tOrdered list: Size: %d\n", list -> size);
        while(sup) {
            printf("\tCharacter: %c Frequency %u\n", sup -> c, sup -> frequency);
            sup = sup -> next;
        }
    }
}

int main(void) {
    //unsined keyword tells that it can't hold negative values
    unsigned char text[] = {"Vamos aprender a programar"};
    unsigned int frequency_table[SIZE];
    initialize_table_with_zero(frequency_table);
    fill_frequency_tab(text, frequency_table);
    print_frequency_tab(frequency_table);
    List list;
    create_list(&list);
    fill_list(frequency_table, &list);
    print_list(&list);
    return EXIT_SUCCESS;
}