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

void dictionary_generate(char ** dictionary, Node *root, char *path, int collumns) {
    char left[collumns], right[collumns];
    if(root -> left == NULL && root -> right == NULL) {
        strcpy(dictionary[root -> c], path);
    } else {
        strcpy(left, path);
        strcpy(right, path);

        strcat(left, "0");
        strcat(right, "1");

        dictionary_generate(dictionary, root -> left, left, collumns);
        dictionary_generate(dictionary, root -> right, right, collumns);
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

//compacting
void compact(unsigned char str[]) {
    FILE *file = fopen("file.wg", "wb");
    int i = 0, j = 7;
    unsigned char byte = 0, mask;
    if(file) {
        while(str[i] != '\0') {
            mask = 1;
            if(str[i] == '1') {
                mask = mask << j;
                byte |= mask;
            }
            i++;
            j--;
            if(j < 0) {
                fwrite(&byte, sizeof(unsigned char), 1, file);
                byte = 0;
                j = 7;
            }
        }
        if(j != 7) {
            fwrite(&byte, sizeof(unsigned char), 1, file);
        }
        fclose(file);
    } else {
        printf("\n\tFailed to open/creat the file on compact\n");
    }
}

void print_compact_file() {
    FILE *file = fopen("file.wg", "rb");
    unsigned char byte;
    if(file) {
        while(fread(&byte, sizeof(unsigned char), 1, file)) {
            printf("%c", byte);
        }
        printf("\n");
        fclose(file);
    } else {
        printf("\n\tFailed to open the file on compact\n");
    }
}

unsigned int is_bit_one(unsigned char byte, int i) {
    unsigned char mask = (1 << i);
    return byte & mask;
}

void descompact(Node *root) {
    FILE *file = fopen("file.wg", "rb");
    Node *sup = root;
    int i = 0;
    unsigned char byte;
    if(file) {
        while(fread(&byte, sizeof(unsigned char), 1, file)) {
            for(i = 7; i >= 0; i--) {
                if(is_bit_one(byte, i)) {
                    sup = sup -> right;
                } else {
                    sup = sup -> left;
                }
                if(!sup -> left && !sup -> right) {
                    printf("%c", sup -> c);
                    sup = root;
                }
            }
        }
        fclose(file);
    } else {
        printf("\n\tFailed to open the file on compact\n");
    }
}

int discover_size() {
    FILE *file = fopen("test.txt", "r");
    int size = 0;
    if(file) {
        while(fgetc(file) != -1) {
            size++;
        }
        fclose(file);
    } else {
        printf("\n\tFailed to open file on discover_size\n");
    }
    return size;
}

void read_text(unsigned char *text) {
    FILE *file = fopen("test.txt", "r");
    char letter;
    int i = 0;
    if(file) {
        while (!feof(file)) {
            letter = fgetc(file);
            if(letter != -1) {
                text[i] = letter;
                i++;
            }
        }
        
        fclose(file);
    } else {
        printf("\n\tFailed to open file on read_text\n");
    }
}

int main(void) {
    //unsined keyword tells that it can't hold negative values
    unsigned char *text;
    unsigned int frequency_table[SIZE];
    int size;
    size = discover_size();
    printf("\nQuantity: %d\n", size);
    text = calloc(size + 2, sizeof(unsigned char));
    read_text(text);
    printf("\nTEXT: \n%s\n", text);
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
    dictionary_generate(dictionary, tree, "", collumns);
    printf("\n\t------Dictionary------\n");
    print_dictionary(dictionary);
    printf("\n\t------Code------\n");
    char *code = coding(dictionary, text);
    printf("%s\n", code);
    printf("\n\t------Decode------\n");
    char *decode = decoding(code, tree);
    printf("%s\n", decode);
    printf("\n\t------Compact------\n");
    compact((unsigned char*)code);
    print_compact_file();
    printf("\n\t------Descompact------\n");
    descompact(tree);
    free(text);
    free(code);
    free(decode);
    for(int i = 0; i < SIZE; i++) {
        free(dictionary[i]);
    }
    free(dictionary);
    return EXIT_SUCCESS;
}