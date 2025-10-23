#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int id;
} Person;

typedef struct node {
    Person person;
    struct node *left, *right;
} TreeNode;

Person insert_person() {
    Person p;
    printf("\tEnter the person's name: ");
    scanf("%49[^\n]", p.name);
    while((getchar()) != '\n');
    printf("\tEnter the person's ID: ");
    scanf("%d", &p.id);
    while((getchar()) != '\n');
    return p;
}

void print_person(Person p) {
    printf("\tID: %d\tName: %s\n", p.id, p.name);
}

void insert(TreeNode **root, Person p) {
    TreeNode *sup = *root;
    while (sup) {
        if(sup -> person.id > p.id) {
            if(!sup -> left) {
                break;
            }
            sup = sup -> left;
        } else {
            if(!sup -> right) {
                break;
            }
            sup = sup -> right;
        }
    }
    TreeNode *new = malloc(sizeof(TreeNode));
    new -> person = p;
    new -> left = NULL;
    new -> right = NULL;
    if(!*root) {
        *root = new;
        return;
    }
    if(sup -> person.id > p.id) {
       sup -> left = new;
    } else {
        sup -> right = new;
    }
}

TreeNode* search(TreeNode *root, int id) {
    while(root) {
        if(root -> person.id == id) {
            return root;
        }
        if(root -> person.id > id) {
            root = root -> left;
        } else {
            root = root -> right;
        }
    }
    return NULL;
}

TreeNode* remove_node(TreeNode *root, int id) {
    if(root) {
        if(root -> person.id == id) {
            //remove a leaf
            if(!root -> left && !root -> right) {
                free(root);
                printf("\n\tRemoved leaf node: %d\n", id);
                return NULL;
            } else {
                //node with 2 children
                if(root -> left && root -> right) {
                    TreeNode *sup = root -> left;
                    while(sup -> right) {
                        sup = sup -> right;
                    }
                    Person p = root -> person;
                    root -> person = sup -> person;
                    sup -> person = p;
                    printf("\tElement changed: %d!\n", id);
                    root -> left = remove_node(root -> left, id);
                    return root;
                    //node with 1 child
                } else {
                    TreeNode *node = root -> left == NULL ? 
                    root -> right : root -> left;
                    free(root);
                    printf("\n\tRemoved node with 1 branch: %d\n", id);
                    return node;
                }
            }
        }  else {
            if(id < root -> person.id) {
                root -> left = remove_node(root -> left, id);
            } else {
                root -> right = remove_node(root -> right, id);
            }
            return root;
        }
    }
    return NULL;
}

int tree_height(TreeNode *root) {
    if(root) {//!NULL
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

int num_of_nodes(TreeNode *root) {
    if(root) {
        return 1 + 
            num_of_nodes(root -> left) + 
            num_of_nodes(root -> right);
    } else {
        return 0;
    }
}

int num_of_leafs(TreeNode *root) {
    if(root) {
        if(!root -> left && !root -> right) {
            return 1;
        }
        return num_of_leafs(root -> left) + num_of_leafs(root -> right);
    } else {
        return 0;
    }
}

void print(TreeNode *root) {
    if(root) {
        print(root -> left);
        print_person(root -> person);
        print(root -> right);
    }
}

int main(void) {
    TreeNode *root = NULL, *node;
    int value = 0, opt;
    do {
        printf("\n\t0 - Exit\n\t1 - Insert\n\t2 - Search\n\t3 - Print\n\t4 - Tree Height\n\t5 - Number of Nodes\n\t6 - Number of Leafs\n\t7 - Remove\n");
        scanf("%d", &opt);
        while((getchar()) != '\n');
        switch (opt) {
            case 0:
                printf("\n\tExiting...\n");
                break;
            case 1:
                insert(&root, insert_person());
                break;
            case 2:
            printf("Enter the id to search: ");
                scanf("%d", &value);
                while((getchar()) != '\n');
                node = search(root, value);
                if(node) {
                    print_person(node->person);
                } else {
                    printf("\n\tPerson not found\n");
                }
                break;
            case 3:
                printf("\n\tPeople: \n");
                print(root);
                printf("\n");
                break;
            case 4:
                printf("\n\tThe tree height is %d\n", tree_height(root));
                break;
            case 5:
                printf("\n\tThe tree have %d nodes\n", num_of_nodes(root));
                break;
            case 6:
                printf("\n\tThe tree have %d leafs\n", num_of_leafs(root));
                break;
            case 7:
                printf("\n\tPeople: \n");
                print(root);
                printf("\n\n");
                printf("Enter the ID of the person to be remove: ");
                scanf("%d", &value);
                root = remove_node(root, value);
                break;
            default:
                printf("\n\tInvalid option\n");
                break;
        }
    } while (opt != 0);
    return EXIT_SUCCESS;
}