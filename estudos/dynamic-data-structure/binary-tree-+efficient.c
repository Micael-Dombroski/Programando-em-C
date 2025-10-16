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

//Recursive search
TreeNode* recursive_search(TreeNode *root, int num) {
    if(root) {
        if(num == root -> value) {
            return root;
        } else if (num < root -> value) {
            return recursive_search(root -> left, num);
        } else {
            return recursive_search(root -> right, num);
        }
    }
    return NULL;
}

TreeNode* search(TreeNode *root, int value) {
    while(root) {
        if(root -> value == value) {
            return root;
        }
        if(root -> value > value) {
            root = root -> left;
        } else {
            root = root -> right;
        }
    }
    return NULL;
}

void print(TreeNode *tree) {
    if(tree) {
        print(tree -> left);
        printf("%d ", tree -> value);
        print(tree -> right);
    }
}

int main(void) {
    TreeNode *tree = NULL, *node;
    int value = 0, opt;
    do {
        printf("\n\t0 - Exit\n\t1 - Insert\n\t2 - Search\n\t3 - Search with recursion\n\t4 - Print\n");
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
        printf("Enter the value to search: ");
            scanf("%d", &value);
            while((getchar()) != '\n');
            node = search(tree, value);
            if(node) {
                printf("\tThe value %d was found!", node -> value);
            } else {
                printf("\n\tValue not found\n");
            }
            break;
        case 3:
            printf("Enter the value to search: ");
            scanf("%d", &value);
            while((getchar()) != '\n');
            node = recursive_search(tree, value);
            if(node) {
                printf("\tThe value %d was found!", node -> value);
            } else {
                printf("\n\tValue wasn't found\n");
            }
            break;
        case 4:
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