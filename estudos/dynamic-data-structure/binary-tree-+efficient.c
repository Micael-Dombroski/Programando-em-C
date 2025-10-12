#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *left, *right;
} TreeNode;

void insert(TreeNode **tree, int value) {
    TreeNode *sup = *tree;
    while(sup) {
        if(sup -> value >= value) {
            tree = &sup -> left;
        } else {
            tree = &sup -> right;
        }
        sup = *tree;
    }
    sup = malloc(sizeof(TreeNode));
    sup -> value = value;
    sup -> left = NULL;
    sup -> right = NULL;
    *tree = sup;
}

void print(TreeNode *tree) {
    if(tree) {
        print(tree -> left);
        printf("%d ", tree -> value);
        print(tree -> right);
    }
}

int main(void) {
    TreeNode *tree = NULL;
    int value = 0, opt;
    do {
        printf("\n\t0 - Exit\n\t1 - Insert\n\t2 - Print\n");
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
            printf("\nValues: ");
            print(tree);
            printf("\n");
            break;
        default:
            printf("\n\tInvalid option\n");
            break;
        }
    } while (opt != 0);

    return EXIT_SUCCESS;
}