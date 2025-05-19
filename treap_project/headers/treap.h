#ifndef TREAP_H
#define TREAP_H
#include "main.h"

// this is the Node structure for the treap
typedef struct TreapNode
{
  int key;      // binary search tree property
  int priority; // heap property
  struct TreapNode *left;
  struct TreapNode *right;
} TreapNode;

/* AUXILIARY FUNCTIONS */

// create a new treap node
/**
 * @param key
 * @return
 */
TreapNode *createNode (int key);

// rotate right (for maintaining heap property)
/**
 * @param y
 * @return
 */
TreapNode *rotateRight (TreapNode *y);

// rotate left (for maintaining heap property)
/**
 * @param x
 * @return
 */
TreapNode *rotateLeft (TreapNode *x);

// split a treap into two treaps
// - all nodes with keys <= k will be in 'left'
// - all nodes with keys > k will be in 'right'
/**
 * @param root
 * @param key
 * @param left
 * @param right
 */
void split (TreapNode *root, int key, TreapNode **left, TreapNode **right);

// merge two treaps
// - all keys in 'left' should be <= all keys in 'right'
/**
 *
 * @param left
 * @param right
 * @return
 */
TreapNode *merge (TreapNode *left, TreapNode *right);

/* TREAP FUNCTIONS */

// insert a key into the treap
/**
 *
 * @param root
 * @param key
 * @return
 */
TreapNode *insert (TreapNode *root, int key);

// search for a key in the treap
/**
 *
 * @param root
 * @param key
 * @return
 */
TreapNode *search (TreapNode *root, int key);

// erase a key from the treap
/**
 *
 * @param root
 * @param key
 * @return
 */
TreapNode *erase (TreapNode *root, int key);

// build a treap from an array of keys
/**
 *
 * @param arr
 * @param n
 * @return
 */
TreapNode *build (int arr[], int n);

// compute the union of two treaps
/**
 *
 * @param t1
 * @param t2
 * @return
 */
TreapNode *unionTreap (TreapNode *t1, TreapNode *t2);

// intersection of two treaps
/**
 *
 * @param t1
 * @param t2
 * @return
 */
TreapNode *intersect (const TreapNode *t1, TreapNode *t2);

// print the treap in-order (for debugging)
/**
 *
 * @param root
 */
void inorder (const TreapNode *root);

/* FREE MEMORY */

// free the memory allocated for the treap
/**
 *
 * @param root
 */
void freeTreap (TreapNode *root);
#endif // TREAP_H
