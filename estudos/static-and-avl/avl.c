#include <stdio.h>
#include <stdlib.h>

/*
   A binary tree can become a degenerate (pathological) tree, 
   where each node has only one child. When this happens, the 
   tree behaves like a linked list, making operations slower.

    We can convert a degenerate tree into a balanced tree. 
    A balanced tree has O(log n) efficiency, while an unbalanced 
    tree can degrade to O(n).

    To balance a tree, we try to keep the height difference 
    between the left and right subtrees as small as possible. 
    In balanced trees like AVL trees, this difference can be at 
    most 1.

    Each node in the tree has a value called the balance factor, 
    which is calculated by subtracting the height of the right 
    subtree from the height of the left subtree.

    To fix imbalance in AVL trees, we use rotations. There are 
    four types: left rotation, right rotation, left-right rotation, 
    and right-left rotation. Single rotations (left or right) fix 
    simple imbalances, while double rotations (left-right or 
    right-left) fix more complex cases where the subtree leans in 
    opposite directions.
*/

typedef struct node {
    int value;
    struct node *left, *right;
    short height;
} Node;

Node *newNode(int x) {
    Node *new = malloc(sizeof(Node));
    if(new) {
        new -> value = x;
        new -> left = NULL;
        new -> right = NULL;
        new -> height = 0;
    } else {
        printf("\n\tFailed to allocate memory on newNode\n");
    }
    return new;
}

short biggest(short a, short b) {
    return a > b ? a : b;
}

short nodeHeight(Node *node) {
    if(node) {
        return node -> height;
    }
    return -1;
}

short balancingFactor(Node *node) {
    // Returns the AVL balance factor of the node:
    //   > 1  → left-heavy (imbalanced)
    //   < -1 → right-heavy (imbalanced)
    //    1,0,-1 → the node is balanced
    // Note: balance factor is based on subtree heights, not 
    //number of nodes.
    if(node) {
        return (nodeHeight(node -> left) - nodeHeight(node -> right));
    } else {
        return 0;
    }
}

Node* leftRotation(Node *root) {
    Node *rightNode, *rightNodeChildAtLeft;
    rightNode = root -> right;//node that will become the new root
    rightNodeChildAtLeft = rightNode -> left;//subtree that will move
    // Perform rotation:
    // The original right child becomes the new root of this subtree.
    rightNode -> left = root;
    root -> right = rightNodeChildAtLeft;
    //new hegiths
    root -> height = biggest(nodeHeight(root -> left), nodeHeight(root -> right)) + 1;
    rightNode -> height = biggest(nodeHeight(rightNode -> left), nodeHeight(rightNode -> right) + 1);
    return rightNode;
}

Node *rightRotation(Node *root) {
    Node *leftNode, *leftNodeChildAtRight;
    leftNode = root -> left;
    leftNodeChildAtRight = leftNode -> right;
    // Perform rotation:
    // The original left child becomes the new root of this subtree.
    leftNode -> right = root;
    root -> left = leftNodeChildAtRight;

    root -> height = biggest(nodeHeight(root -> left), nodeHeight(root -> right)) + 1;
    leftNode -> height = biggest(nodeHeight(leftNode -> left), nodeHeight(leftNode -> right)) + 1;
    return leftNode;
}

Node* rightLeftRotation(Node *root) {
    root -> right = rightRotation(root -> right);
    return leftRotation(root);
}

Node* leftRightRotation(Node *root) {
    root -> left = leftRotation(root -> left);
    return rightRotation(root);
}

Node* balance(Node *root) {
    short bf = balancingFactor(root);
    // > 1  → left-heavy (imbalanced)
    // < -1 → right-heavy (imbalanced)
    // 1,0,-1 → the node is balanced
    if(bf < -1 && balancingFactor(root -> right) <= 0) {
        /*
                 o                        o
                / \                     /   \
               o   o       \\\\       o       o
              / \          ////     /   \   /   \
             o   o                 o     o o     o
            / \
           o   o
        
        */
        root = leftRotation(root);
    } else if (bf > 1 && balancingFactor(root -> left) >= 0) {
        /*
                 o                            o
                / \                         /   \
               o   o           \\\\       o       o
                  / \          ////     /   \   /   \
                 o   o                 o     o o     o
                    / \
                   o   o
        
        */
        root = rightRotation(root);
    } else if(bf > 1 && balancingFactor(root -> left) < 0) {
        /*
                 o                o                       o
                / \              / \                    /   \
               o   o   \\\\     o   o      \\\\       o       o
              / \      ////    / \         ////     /   \   /   \
             o   o            o   o                o     o o     o
                / \          / \            
               o   o        o   o            
        
        */
        root = leftRightRotation(root);
    } else if(bf < -1 && balancingFactor(root -> right) > 0) {
        /*
                 o                o                       o
                / \              / \                    /   \
               o   o   \\\\     o   o      \\\\       o       o
                  / \  ////        / \     ////     /   \   /   \
                 o   o            o   o            o     o o     o
                / \                  / \            
               o   o                o   o            
        
        */
        root = rightLeftRotation(root);
    }
    return root;
}

Node* insert(Node *root, int x) {
    if(!root) {//empty tree
        return newNode(x);
    } else {
        if(x < root -> value) {//insert on left or right
            root -> left = insert(root -> left, x);
        } else {
            root -> right = insert(root -> right, x);
        }
    }
    
    //nodes height recalculation
    root -> height = biggest(nodeHeight(root -> left), nodeHeight(root -> right)) + 1;

    //check if it need to balance the tree
    root = balance(root);

    return root;
}

Node* removeNode(Node *root, int key) {
    if(!root) {
        printf("Value not found\n");
        return NULL;
    } else {
        if(root -> value == key) {
            if(!root -> left && !root -> right) {//leaft node
                free(root);
                printf("Leaf element was removed\n");
                return NULL;
            } else {
                if(root -> left && root -> right) {//node with 2 childs
                    Node *sup = root -> left;
                    while (sup -> right) {
                        sup = sup -> right;
                    }
                    root -> value = sup -> value;
                    sup -> value = key;
                    printf("Chaged element: %d!\n", key);
                    root -> left = removeNode(root -> left, key);
                    return root;
                } else {
                    Node *sup;
                    if (root -> left){ //node with 1 child at left
                        sup = root -> left;
                    } else { //node with 1 child at right
                        sup = root -> right;
                    }
                    free(root);
                    printf("Element with 1 child removed: %d!\n", key);
                    return sup;
                }
            }
        } else {
            if(key < root -> value) {
                root -> left = removeNode(root -> left, key);
            } else {
                root -> right = removeNode(root -> right, key);
            }
        }
        root -> height = biggest(nodeHeight(root -> left), nodeHeight(root -> right)) + 1;

        root = balance(root);

        return root;
    }
}

void print_avl(Node *root, int lvl) {
    int i;
    if(root) {
        print_avl(root -> right, lvl + 1);
        printf("\n\n");

        for(i = 0; i < lvl; i++) {
            printf("\t");
        }
        printf("%d(%d)", root -> value, i);
        print_avl(root -> left, lvl + 1);
    }
}

int print_lvl(Node *root, int value) {
    if(!root) {
        printf("Value not found!\n");
        return -1;
    }
    if(root -> value == value) {
        return 0;
    }
    int lvl;
    if(root -> value > value) {
        lvl = print_lvl(root -> left, value);
    } else if(root -> value < value) {
        lvl = print_lvl(root -> right, value);
    }

    if(lvl == -1) return -1;
    return lvl +1;
}

int main(void) {
    int opt, ret = 0, value;
    Node *tree = NULL;
    do {
        printf("\t===Menu===\n\t[1] Add\n\t[2] Remove\n\t[3] Print\n\t[4] Search\n\t[0] Exit\n");
        do {
            printf("Choose an option: ");
            ret = scanf("%d", &opt);
            if(ret != 1) {
                printf("Invalid Input: Enter an Integer value\n");
            }
        } while (ret != 1);
        switch (opt)
        {
        case 1:
            printf("Enter a value: ");
            while((scanf("%d", &value)) != 1);
            tree = insert(tree, value);
            break;
        case 2:
            if(tree) {
                printf("Enter a value to remove: ");
                while ((scanf("%d", &value)) != 1);
                tree = removeNode(tree, value);
            } else {
                printf("The tree is empty\n");
            }
            break;
        case 3:
            if(tree) {
                print_avl(tree, 0);
            } else {
                printf("The tree is empty\n");
            }
            
            printf("\n\n");
            break;
        case 4:
            if(tree) {
                printf("Enter a value to search for: ");
                while((scanf("%d", &value)) != 1);
                int lvl = print_lvl(tree, value);
                if(lvl >= 0) {
                    printf("The value %d is in the tree at level %d\n", value, lvl);
                }
            } else {
                printf("The tree is empty\n");
            }
            break;
        case 0:
            printf("Exiting...\n");
            break;
        default:
        printf("Invalid option\n");
            break;
        }
    } while (opt != 0);

    return EXIT_SUCCESS;
}