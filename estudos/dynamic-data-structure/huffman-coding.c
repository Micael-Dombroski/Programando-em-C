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

//frequency table
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


//list
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

//tree
Node* remove_start_node(List *list) {
    Node *sup = NULL;
    if(list -> start) {
        sup = list -> start;
        list -> start = sup -> next;
        list -> size--;
        sup -> next = NULL;
    }

    return sup;
}

Node* build_tree(List *list) {
    Node *first, *second, *new = NULL;
    while(list -> size > 1) {
        first = remove_start_node(list);
        second = remove_start_node(list);
        new = malloc(sizeof(Node));
        if(new) {
            new -> c = '+';
            new -> frequency = first -> frequency + second -> frequency;
            new -> left = first;
            new -> right = second;
            new -> next = NULL;
            ordered_insert(list, new);
        } else {
            printf("\n\tFailed to allocate memory on build_tree\n");
            break;
        }
    }
    return list -> start;
}

void print_tree(Node *root, int size) {
    if(!root -> left && !root -> right) {
        printf("\tLeaf: %c\tHeight: %d\n", root -> c, size);
    } else {
        print_tree(root -> left, size + 1);
        print_tree(root -> right, size +1);
    }
}

int main(void) {
    //unsined keyword tells that it can't hold negative values
    unsigned char text[] = {"Vamos aprender a programar"};
    unsigned int frequency_table[SIZE];
    printf("\n\t-------Frequency Table-------\n");
    initialize_table_with_zero(frequency_table);
    fill_frequency_tab(text, frequency_table);
    print_frequency_tab(frequency_table);
    List list;
    create_list(&list);
    fill_list(frequency_table, &list);
    print_list(&list);
    Node *tree = build_tree(&list);
    printf("\n\t-------Huffman Tree-------\n");
    print_tree(tree, 0);
    return EXIT_SUCCESS;
}