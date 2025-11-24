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

int main(void) {


    return EXIT_SUCCESS;
}