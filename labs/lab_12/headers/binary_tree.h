#ifndef BINARYTREE_BINARY_TREE_H
#define BINARYTREE_BINARY_TREE_H
#include "main.h"
#include "book.h"

typedef struct Node{
    Book_t info;
    struct Node *left, *right;
}Node;

/**
 * Allocate memory for a new node
 * @param newData
 * @return the allocated node item
 */
Node *createNewNode(Book_t newData);
/**
 * Insert a new node to the left of the root
 * @param root
 * @param newData
 * @return pointer to the inserted node
 */
Node *insertLeft(Node *root, Book_t newData);
/**
 * Insert a new node to the right of the root
 * @param root
 * @param newData
 * @return pointer to the inserted node
 */
Node *insertRight(Node *root, Book_t newData);
/**
 * ROOT-LEFT-RIGHT order of traversal
 * @param root
 */
 ///1, 2, 4, 8, 9, 5, 3, 6, 7
void preorderTraversal(Node *root);
/**
 * LEFT-ROOT-RIGHT order of traversal
 * @param root
 */
 ///8, 4, 9, 2, 5, 1, 6, 3, 7
void inorderTraversal(Node *root);
/**
 * LEFT-RIGHT-ROOT order of traversal
 * @param root
 */
 ///8, 9, 4, 5, 2, 6, 7, 3, 1
void postorderTraversal(Node *root);

/**
 * Deallocate memory
 * @param root
 */
void destroyBinaryTree(Node **root);

#endif //BINARYTREE_BINARY_TREE_H
