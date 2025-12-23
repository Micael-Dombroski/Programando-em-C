#include <stdio.h>
#include <stdlib.h>


typedef struct {
    char name[25];
    int age;
    int id;
} Person;

typedef struct node {
    Person *person;
    struct node *left, *right;
    short height;
} Node;

Node* newNode(Person *person) {
    Node *new = malloc(sizeof(Person));
    if(new) {
        new -> person = person;
        new  -> left = NULL;
        new -> right = NULL;
        new -> height = 0;
    } else {
        printf("\n\tFailed to allocate memory at newNode\n");
    }

    return new;
}

short biggest(int a, int b) {
    return a > b ? a : b;
}

short nodeHeight(Node *node) {
    if(node) {
        return node -> height;
    } else {
        return -1;
    }
}

short balanceFactor(Node *node) {
    if(node) {
        return (nodeHeight(node -> left) - nodeHeight(node -> right));
    } else {
        return 0;
    }
}

Node* leftRotation(Node *node) {
    Node *sup1, *sup2;
    sup1 = node -> right;
    sup2 = sup1 -> left;

    sup1 -> left = node;
    node -> right = sup2;

    node -> height = biggest(nodeHeight(node -> left), nodeHeight(node -> right)) + 1;
    sup1 -> height = biggest(nodeHeight(sup1 -> left), nodeHeight(sup1 -> right)) + 1;

    return sup1;
}

Node* rightRotation(Node *node) {
    Node *sup1, *sup2;

    sup1 = node -> left;
    sup2 = sup1 -> right;

    sup1 -> right = node;
    node -> left = sup2;

    node -> height = biggest(nodeHeight(node -> left), nodeHeight(node -> right)) + 1;
    sup1 -> height = biggest(nodeHeight(sup1 -> left), nodeHeight(sup1 -> right)) + 1;

    return sup1;
}

Node* leftRightRotation(Node *node) {
    node -> left = leftRotation(node -> left);
    return rightRotation(node);
}

Node* rightLeftRotation(Node *node) {
    node -> right = rightRotation(node -> right);
    return leftRotation(node);
}

Node* balance(Node *root) {
    short bf = balanceFactor(root);

    if(bf < -1 && balanceFactor(root -> right) <= 0) {
        root = leftRotation(root);
    } else if(bf > 1 && balanceFactor(root -> left) >= 0) {
        root = rightRotation(root);
    } else if(bf > 1 && balanceFactor(root -> left) < 0) {
        root = leftRightRotation(root);
    } else if(bf < -1 && balanceFactor(root -> right) > 0) {
        root = rightLeftRotation(root);
    }
    return root;
}

Node* insert(Node *root, Person *p) {
    if(root == NULL) {
        return newNode(p);
    } else {
        if( p -> id < root -> person -> id) {
            root -> left = insert(root -> left, p);
        } else if (p -> id > root -> person -> id) {
            root -> right = insert(root -> right, p);
        } else {
            printf("\n\tNon-ralized insert!\n\tThe person with id %d already exist\n", p -> id);
        }
    }
    root -> height = biggest(nodeHeight(root -> left), nodeHeight(root -> right)) + 1;
    root = balance(root);
    return root;
}

Node* removePerson(Node *root, int key) {
    if(root) {
        if(root -> person -> id == key) {
            if(!root -> left && !root -> right) {
                free(root);
                printf("\n\tLeaf element removed Person with ID '%d'\n", key);
            } else {
                if(root -> left  && root -> right) {
                    Node *sup = root -> left;
                    while(sup -> right) {
                        sup = sup -> right;
                    }
                    Person *supPerson;
                    supPerson = root -> person;
                    root -> person = sup -> person;
                    sup -> person = supPerson;
                    printf("\n\tChanged element: Person with ID '%d'\n", key);
                    root -> left = removePerson(root -> left, key);
                    return root;
                } else {
                    Node *sup;
                    if(root -> left) {
                        sup = root -> left;
                    } else if(root -> right) {
                        sup = root -> right;
                    }
                    free(root);
                    printf("\n\tNode with 1 child was removed: Person with ID '%d'\n", key);
                    return sup;
                }
            }
        } else {
            if(key < root -> person -> id) {
                root -> left = removePerson(root -> left, key);
            } else {
                root -> right = removePerson(root -> right, key);
            }
        }
        root -> height = biggest(nodeHeight(root -> left), nodeHeight(root -> right)) + 1;
        root = balance(root);
        return root;
    } else {
        printf("\n\tID not found\n");
        return root;
    }
}

void printPerson(Person *person) {
    printf("Name: %s ID: %d Age: %d\n", person -> name, person -> id, person -> age);
}

void printAVL(Node *root, int lvl) {
    int i;
    if(root) {
        printAVL(root -> right, lvl + 1);
        printf("\n\n");
        for ( i = 0; i < lvl; i++) {
            printf("\t");
        }
        printPerson(root -> person);
        printAVL(root -> left, lvl + 1);
    }
}

int printLvl(Node *root, int id) {
    if(!root) {
        printf("Value not found!\n");
        return -1;
    }
    if(root -> person -> id == id) {
        return 0;
    }
    int lvl;
    if(root -> person -> id > id) {
        lvl = printLvl(root -> left, id);
    } else if(root -> person  -> id < id) {
        lvl = printLvl(root -> right, id);
    }

    if(lvl == -1) return -1;
    return lvl +1;
}

int main() {
    int opt, value, ret;
    Node *tree = NULL;
    Person *p;
    do {
        printf("\t===Menu===\n\t[1] Add\n\t[2] Remove\n\t[3] Print\n\t[4] Search\n\t[0] Exit\n");
        do {
            printf("Choose an option: ");
            ret = scanf("%d", &opt);
            while((getchar()) != '\n');
            if(ret != 1) {
                printf("Invalid Input: Enter an Integer value\n");
            }
        } while (ret != 1);
        switch (opt)
        {
        case 1:
            p = malloc(sizeof(Person));
            if(!p) {
                break;
            }
            printf("Enter the name: \n");
            scanf("%25[^\n]", p -> name);
            while((getchar()) != '\n');
            printf("Enter the ID: \n");
            while((scanf("%d", &p -> id)) != 1);
            while((getchar()) != '\n');
            printf("Enter the age: \n");
            while((scanf("%d", &p -> age)) != 1);
            while((getchar()) != '\n');
            tree = insert(tree, p);
            break;
        case 2:
            if(tree) {
                printf("Enter a ID to remove: ");
                while ((scanf("%d", &value)) != 1);
                tree = removePerson(tree, value);
            } else {
                printf("The tree is empty\n");
            }
            break;
        case 3:
            if(tree) {
                printAVL(tree, 0);
            } else {
                printf("The tree is empty\n");
            }
            
            printf("\n\n");
            break;
        case 4:
            if(tree) {
                printf("Enter a value to search for: ");
                while((scanf("%d", &value)) != 1);
                int lvl = printLvl(tree, value);
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

