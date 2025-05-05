#include <stdio.h>
#include "headers/binary_tree.h"

int main() {
/* creating the tree */
  // create the root
    Node *root = createNewNode(100);
  // fill up the tree
    insertLeft(root, 500);
    insertRight(root, 600);

    insertLeft(root->right, 700);
    insertRight(root->right, 800);

    insertRight(root->right->right, 900);
    insertRight(root->right->right->right, 1000);

/* traversals */
    printf("\nPreorder: ");
    preorderTraversal(root);
    printf("\nInorder: ");
    inorderTraversal(root);
    printf("\nPostorder: ");
    postorderTraversal(root);

/* deallocate */
    destroyBinaryTree(&root);

    return 0;
}
