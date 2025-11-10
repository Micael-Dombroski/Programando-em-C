#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

//dictionary table
int tree_height(Node *root) {
    if(root) {
        int hLeft = tree_height(root -> left);
        int hRight = tree_height(root -> right);
        if(hLeft > hRight) {
            return hLeft + 1;
        } else {
            return hRight + 1;
        }
    } else {
        return -1;
    }
}

char** dictionary_allocate(int collumns) {
    char **dictionary;
    dictionary = malloc(sizeof(char*) * SIZE);
    if(dictionary) {
        for(int i = 0; i < SIZE; i++) {
            //we use calloc here because it initializes the allocated memory
            //to zero, preventing the presence of garbage values
            dictionary[i] = calloc(collumns, sizeof(char));
            if(!*(dictionary + i)) {
                printf("\n\tFailed to allocate memory on dictionary_allocate\n");
                return NULL;
            }
        }
        return dictionary;
    } else {
        printf("\n\tFailed to allocate memory on dictionary_allocate\n");
        return NULL;
    }
}

void dicitionary_generate(char ** dictionary, Node *root, char *path, int collumns) {
    char left[collumns], right[collumns];
    if(root -> left == NULL && root -> right == NULL) {
        strcpy(dictionary[root -> c], path);
    } else {
        strcpy(left, path);
        strcpy(right, path);

        strcat(left, "0");
        strcat(right, "1");

        dicitionary_generate(dictionary, root -> left, left, collumns);
        dicitionary_generate(dictionary, root -> right, right, collumns);
    }
}

void print_dictionary(char **dicitionary) {
    for(int i = 0; i < SIZE; i++) {
        if(strlen(dicitionary[i]) > 0) {
            printf("\t%3d: %c: %s\n", i, i, dicitionary[i]);
        }
    }
}

//coding text
int string_size_calc(char **dictionary, unsigned char *text) {
    int i = 0, size = 0;
    while(text[i] != '\0') {
        size = size + strlen(dictionary[text[i]]);
        i++;
    }
    return size + 1;
}

char* coding(char **dictionary, unsigned char *text) {
    int size = string_size_calc(dictionary, text);
    char *code = calloc(size, sizeof(char));
    int i = 0;
    while(text[i] != '\0') {
        strcat(code, dictionary[text[i]]);
        i++;
    }
    return code;
}

//decoding text
char* decoding(char *code, Node *root) {
    char *decode = calloc(strlen(code), sizeof(char));
    int i = 0;
    Node *sup = root;
    while(code[i] != '\0') {
        if(!sup -> left && !sup -> right) {
            char str[2];
            str[0] = sup -> c;
            str[1] = '\0';
            strcat(decode, str);
            sup = root;
        }
        if(code[i] == '0') {
            sup = sup -> left;
        }
        if(code[i] == '1') {
            sup = sup -> right;
        }
        i++;
    }
    return decode;
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
    int collumns = tree_height(tree) + 1;
    char **dictionary;
    dictionary = dictionary_allocate(collumns);
    dicitionary_generate(dictionary, tree, "", collumns);
    printf("\n\t------Dictionary------\n");
    print_dictionary(dictionary);
    printf("\n\t------Code------\n");
    char *code = coding(dictionary, text);
    printf("%s\n", code);
    printf("\n\t------Decode------\n");
    char *decode = decoding(code, tree);
    printf("%s\n", decode);
    return EXIT_SUCCESS;
}