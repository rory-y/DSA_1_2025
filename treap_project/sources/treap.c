#include "../headers/treap.h"

/* AUXILIARY and HELPER FUNCTIONS */

// create a new treap node
TreapNode *
createNode (int key)
{
  TreapNode *newNode = (TreapNode *)malloc (sizeof (TreapNode));
  if (newNode == NULL)
    {
      fprintf (stderr, "Memory allocation failed\n");
      exit (EXIT_FAILURE);
    }
  newNode->key = key;
  newNode->priority = rand () % 100001; // random priority
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

// rotate right (for maintaining heap property)
TreapNode *
rotateRight (TreapNode *y)
{
  TreapNode *x = y->left;
  TreapNode *T2 = x->right;
  // perform rotation
  x->right = y;
  y->left = T2;
  return x; // New root after rotation
}

// rotate left (for maintaining heap property)
TreapNode *
rotateLeft (TreapNode *x)
{
  TreapNode *y = x->right;
  TreapNode *T2 = y->left;
  // perform rotation
  y->left = x;
  x->right = T2;
  return y; // New root after rotation
}

// split a treap into two treaps
// - all nodes with keys <= k will be in 'left'
// - all nodes with keys > k will be in 'right'
void
split (TreapNode *root, int key, TreapNode **left, TreapNode **right)
{
  if (root == NULL)
    {
      *left = NULL;
      *right = NULL;
      return;
    }
  if (root->key <= key)
    {
      split (root->right, key, &root->right, right);
      *left = root;
    }
  else
    {
      split (root->left, key, left, &root->left);
      *right = root;
    }
}

// merge two treaps
// - all keys in 'left' should be <= all keys in 'right'
TreapNode *
merge (TreapNode *left, TreapNode *right)
{
  // base cases
  if (left == NULL)
    return right;
  if (right == NULL)
    return left;
  // maintain heap property during merge
  if (left->priority > right->priority)
    {
      // left node becomes root
      left->right = merge (left->right, right);
      return left;
    }
  else
    {
      // right node becomes root
      right->left = merge (left, right->left);
      return right;
    }
}

/* TREAP FUNCTIONS */
// insert a key into the treap
TreapNode *
insert (TreapNode *root, int key)
{
  // if tree is empty, return a new node
  if (root == NULL)
    return createNode (key);
  // if key already exists, return without inserting
  if (key == root->key)
    return root;
  // insert into the appropriate subtree
  if (key < root->key)
    {
      root->left = insert (root->left, key);
      // Fix heap property if violated
      if (root->left->priority > root->priority)
        root = rotateRight (root);
    }
  else
    {
      root->right = insert (root->right, key);
      // fix heap property if violated
      if (root->right->priority > root->priority)
        root = rotateLeft (root);
    }
  return root;
}

// search for a key in the treap
TreapNode *
search (TreapNode *root, int key)
{
  // base cases: root is NULL or key is at root
  if (root == NULL || root->key == key)
    return root;
  // key is greater than root's key
  if (root->key < key)
    return search (root->right, key);
  // key is smaller than root's key
  return search (root->left, key);
}

// erase a key from the treap
TreapNode *
erase (TreapNode *root, int key)
{
  // base case: If tree is empty
  if (root == NULL)
    return NULL;
  // recur to the appropriate subtree
  if (key < root->key)
    {
      root->left = erase (root->left, key);
    }
  else if (key > root->key)
    {
      root->right = erase (root->right, key);
    }
  else
    {
      // this is the node to be deleted
      // case 1: Node is a leaf
      if (root->left == NULL && root->right == NULL)
        {
          free (root);
          return NULL;
        }
      // case 2: Node has only one children
      // or
      // case 3: Node has two children
      // either way, we can use merge to handle it
      else
        {
          TreapNode *temp = merge (root->left, root->right);
          free (root);
          return temp;
        }
    }
  return root;
}

// build a treap from an array of keys
TreapNode *
build (int arr[], int n)
{
  TreapNode *root = NULL;
  for (int i = 0; i < n; i++)
    {
      root = insert (root, arr[i]);
    }
  return root;
}

// compute the union of two treaps
TreapNode *
unionTreap (TreapNode *t1, TreapNode *t2)
{
  if (t1 == NULL)
    return t2;
  if (t2 == NULL)
    return t1;

  // ensure heap property: higher priority node becomes root
  if (t1->priority < t2->priority)
    {
      // Swap t1 and t2 so t1 has higher priority
      TreapNode *temp = t1;
      t1 = t2;
      t2 = temp;
    }

  // split t2 around t1's key
  TreapNode *left = NULL;
  TreapNode *right = NULL;
  split (t2, t1->key, &left, &right);

  // recursively compute union of corresponding parts
  t1->left = unionTreap (t1->left, left);
  t1->right = unionTreap (t1->right, right);

  return t1;
}

// intersection of two treaps
TreapNode *
intersect (const TreapNode *t1, TreapNode *t2)
{
  if (t1 == NULL || t2 == NULL)
    return NULL;

  // make a copy of t2 for search
  TreapNode *searchResult = search (t2, t1->key);

  // initialize result
  TreapNode *result = NULL;

  // if the key exists in both trees
  if (searchResult != NULL)
    {
      // create a new node with this key for our result
      result = createNode (t1->key);
      // copy the priority to maintain treap properties
      result->priority = t1->priority;

      // recursively find intersection for left and right subtrees
      result->left = intersect (t1->left, t2);
      result->right = intersect (t1->right, t2);
    }
  else
    {
      // the key doesn't exist in t2
      // check left and right subtrees separately
      TreapNode *leftIntersect = intersect (t1->left, t2);
      TreapNode *rightIntersect = intersect (t1->right, t2);

      // merge the results
      result = merge (leftIntersect, rightIntersect);
    }
  return result;
}

/* PRINTING OUT THE TREAP */

// print the treap in-order (for debugging)
void
inorder (const TreapNode *root)
{
  if (root != NULL)
    {
      inorder (root->left);
      printf ("Key: %d, Priority: %d\n", root->key, root->priority);
      inorder (root->right);
    }
}

/* FREE MEMORY */

// free the memory allocated for the treap
void
freeTreap (TreapNode *root)
{
  if (root != NULL)
    {
      freeTreap (root->left);
      freeTreap (root->right);
      free (root);
    }
}
