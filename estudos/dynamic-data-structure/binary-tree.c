#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *right, *left;
} TreeNode;

void insert(TreeNode **tree, int value) {
    TreeNode *node = malloc(sizeof(TreeNode));
    if(node) {
        node -> value = value;
        node -> left = NULL;
        node -> right = NULL;
        if(*tree == NULL) {
            *tree = node;
        } else {
            if((*tree) -> value >= node -> value) {
                insert(&((*tree) -> left), value);
            } else {
                insert(&((*tree) -> right), value);
            }
        }
    } else {
        printf("\n\tFailed to allocate memory\n");
    }
}

void easy_print(TreeNode *root) {
    if(root) {
        printf("%d ", root -> value);
        easy_print(root -> left);
        easy_print(root -> right);
    }
}

void ordered_print(TreeNode *tree) {
    if(tree) {
        ordered_print(tree -> left);
        printf("%d ", tree -> value);
        ordered_print(tree -> right); 
    }
}

int main(void) {
    TreeNode *tree = NULL;
    int value = 0, opt;
    do {
        printf("\n\t0 - Exit\n\t1 - Insert\n\t2 - Easy Print\n\t3 - Ordered Print\n");
        scanf("%d", &opt);
        switch (opt) {
        case 0:
            printf("\n\tExiting...\n");
            break;
        case 1:
            printf("Enter an integer value: ");
            scanf("%d", &value);
            while((getchar()) != '\n');
            insert(&tree, value);
            break;
        case 2:
            printf("\nEasy print: ");
            easy_print(tree);
            printf("\n");
            break;
        case 3:
            printf("\nOrdered print: ");
            ordered_print(tree);
            printf("\n");
            break;
        default:
            printf("\n\tInvalid option\n");
            break;
        }
    } while (opt != 0);
    return EXIT_SUCCESS;
}