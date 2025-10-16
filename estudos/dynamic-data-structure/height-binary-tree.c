#include <stdio.h>
#include <stdlib.h>
//Height x Deep
/*
    Height -> number of edges on the logest path from root to a leaf
        -Leaf is a node with no children
    Deep -> distance from the root to a specific node
*/
typedef struct node {
    int value;
    struct node *left, *right;
} TreeNode;

void insert(TreeNode **tree, int value) {
    TreeNode *sup = *tree;
    while(sup) {//!NULL
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
    if(root) {//!NULL
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
    while(root) {//!NULL
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

int tree_height(TreeNode *tree) {
    if(tree) {//!NULL
        int hLeft = tree_height(tree -> left);
        int hRight = tree_height(tree -> right);
        if(hLeft > hRight) {
            return hLeft + 1;
        } else {
            return hRight + 1;
        }
    } else {
        return -1;
    }
}
int num_of_nodes(TreeNode *tree) {
    if(tree) {//!NULL
        return 1 + num_of_nodes(tree -> left) + 
            num_of_nodes(tree -> right);
    }
    return 0;
}

int num_of_leafs(TreeNode *tree) {
    if(tree) {//!NULL
        if(tree -> left == NULL && tree -> right == NULL) {
            return 1;//Is a leaf
        }
        return num_of_leafs(tree -> left) + 
            num_of_leafs(tree -> right);
    }
    return 0;
}

TreeNode* remove_leaf(TreeNode *tree, int value) {
    if(tree) {
        if(tree -> value == value) {
            if(tree -> left == NULL && tree -> right == NULL) {
                free(tree);
                printf("\n\tRemoved leaf node: %d\n", value);
                return NULL;
            } else if(tree -> left != NULL && tree -> right  != NULL) {
                TreeNode *node = tree -> right;
                insert(&node, tree -> left -> value);
                free(tree);
                printf("\n\tRemoved node with 2 branches: %d\n", value);
                return node;
            } else {
                TreeNode *node; 
                if (tree -> right == NULL) {
                    node = tree -> left;
                } else {
                    node = tree -> right;
                }
                free(tree);
                printf("\n\tRemoved node with 1 branche: %d\n", value);
                return node;
            }
        } else {
            if(value < tree -> value) {
                tree -> left = remove_leaf(tree -> left, value);
            } else {
                tree -> right = remove_leaf(tree -> right, value);
            }
            return tree;
        }
    }
    printf("\n\tValue not found\n");
    return NULL;
}

void print(TreeNode *tree) {
    if(tree) {//!NULL
        print(tree -> left);
        printf("%d ", tree -> value);
        print(tree -> right);
    }
}

int main(void) {
    TreeNode *tree = NULL, *node;
    int value = 0, opt;
    do {
        printf("\n\t0 - Exit\n\t1 - Insert\n\t2 - Search\n\t3 - Search with recursion\n\t4 - Print\n\t5 - Tree Height\n\t6 - Number of Nodes\n\t7 - Number of Leafs\n\t8 - Remove\n");
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
            printf("\n\tValues: ");
            print(tree);
            printf("\n");
            break;
        case 5:
            printf("\n\tThe tree height is %d\n", tree_height(tree));
            break;
        case 6:
            printf("\n\tThe tree have %d nodes\n", num_of_nodes(tree));
            break;
        case 7:
            printf("\n\tThe tree have %d leafs\n", num_of_leafs(tree));
            break;
        case 8:
            printf("\n\tValues: ");
            print(tree);
            printf("\n\n");
            printf("Enter the node value to remove: ");
            scanf("%d", &value);
            tree = remove_leaf(tree, value);
            break;
        default:
            printf("\n\tInvalid option\n");
            break;
        }
    } while (opt != 0);
    return EXIT_SUCCESS;
}