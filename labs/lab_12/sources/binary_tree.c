#include "../headers/binary_tree.h"
#include "../headers/book.h"

Node *createNewNode(Book_t newData) {
    Node *newItem = (Node*) malloc(sizeof (Node));
    if(!newItem)
    {
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
    newItem->info = newData;
    newItem->left = newItem->right = NULL ;
    return newItem;
}

Node *insertLeft(Node *root, Book_t newData) {
    root->left = createNewNode(newData);
    return root->left;
}

Node *insertRight(Node *root, Book_t newData) {
    root->right= createNewNode(newData);
    return root->right;
}

void preorderTraversal(Node *root) {
    if(root == NULL) return;
    printBook (root->info);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void inorderTraversal(Node *root) {
    if(root == NULL) return;
    inorderTraversal(root->left);
    printBook (root->info);
    inorderTraversal(root->right);
}


void postorderTraversal(Node *root) {
    if(root == NULL) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printBook (root->info);
}

void destroyBinaryTree(Node **root) {
    if ((*root) != NULL) {
        destroyBinaryTree(&(*root)->left);
        destroyBinaryTree(&(*root)->right);
        free(*root);
        *root = NULL;
    }
}
