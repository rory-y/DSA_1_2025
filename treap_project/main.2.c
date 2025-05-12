#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Node structure for our treap
typedef struct TreapNode {
    int key;               // BST property
    int priority;          // Heap property
    struct TreapNode* left;
    struct TreapNode* right;
} TreapNode;

// Function to create a new treap node
TreapNode* createNode(int key) {
    TreapNode* newNode = (TreapNode*)malloc(sizeof(TreapNode));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    newNode->key = key;
    newNode->priority = rand();  // Random priority
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Function to rotate right (for maintaining heap property)
TreapNode* rotateRight(TreapNode* y) {
    TreapNode* x = y->left;
    TreapNode* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    return x;  // New root after rotation
}

// Function to rotate left (for maintaining heap property)
TreapNode* rotateLeft(TreapNode* x) {
    TreapNode* y = x->right;
    TreapNode* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    return y;  // New root after rotation
}

// Function to split a treap into two treaps
// All nodes with keys <= k will be in 'left'
// All nodes with keys > k will be in 'right'
void split(TreapNode* root, int key, TreapNode** left, TreapNode** right) {
    if (root == NULL) {
        *left = NULL;
        *right = NULL;
        return;
    }

    if (key < root->key) {
        // Current node and right subtree go to 'right'
        split(root->left, key, left, &root->left);
        *right = root;
    } else {
        // Current node and left subtree go to 'left'
        split(root->right, key, &root->right, right);
        *left = root;
    }
}

// Function to merge two treaps
// All keys in 'left' should be <= all keys in 'right'
TreapNode* merge(TreapNode* left, TreapNode* right) {
    // Base cases
    if (left == NULL) return right;
    if (right == NULL) return left;

    // Maintain heap property during merge
    if (left->priority > right->priority) {
        // Left node becomes root
        left->right = merge(left->right, right);
        return left;
    } else {
        // Right node becomes root
        right->left = merge(left, right->left);
        return right;
    }
}

// Function to insert a key into the treap
TreapNode* insert(TreapNode* root, int key) {
    // If tree is empty, return a new node
    if (root == NULL)
        return createNode(key);

    // If key already exists, return without inserting
    if (key == root->key)
        return root;

    // Insert into the appropriate subtree
    if (key < root->key) {
        root->left = insert(root->left, key);

        // Fix heap property if violated
        if (root->left->priority > root->priority)
            root = rotateRight(root);
    } else {
        root->right = insert(root->right, key);

        // Fix heap property if violated
        if (root->right->priority > root->priority)
            root = rotateLeft(root);
    }

    return root;
}

// Function to search for a key in the treap
TreapNode* search(TreapNode* root, int key) {
    // Base cases: root is NULL or key is at root
    if (root == NULL || root->key == key)
        return root;

    // Key is greater than root's key
    if (root->key < key)
        return search(root->right, key);

    // Key is smaller than root's key
    return search(root->left, key);
}

// Function to erase a key from the treap
TreapNode* erase(TreapNode* root, int key) {
    // Base case: If tree is empty
    if (root == NULL)
        return NULL;

    // Recur to the appropriate subtree
    if (key < root->key) {
        root->left = erase(root->left, key);
    } else if (key > root->key) {
        root->right = erase(root->right, key);
    } else {
        // This is the node to be deleted

        // Case 1: Node is a leaf
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        // Case 2: Node has only one child or Case 3: Node has two children
        // Either way, we can use merge to handle it
        else {
            TreapNode* temp = merge(root->left, root->right);
            free(root);
            return temp;
        }
    }

    return root;
}

// Function to build a treap from an array of keys
TreapNode* build(int arr[], int n) {
    TreapNode* root = NULL;

    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }

    return root;
}

// Function to compute the union of two treaps
TreapNode* unionTreap(TreapNode* t1, TreapNode* t2) {
    if (t1 == NULL) return t2;
    if (t2 == NULL) return t1;

    // Ensure heap property: higher priority node becomes root
    if (t1->priority < t2->priority) {
        // Swap t1 and t2 so t1 has higher priority
        TreapNode* temp = t1;
        t1 = t2;
        t2 = temp;
    }

    // Split t2 around t1's key
    TreapNode* left = NULL;
    TreapNode* right = NULL;
    split(t2, t1->key, &left, &right);

    // Recursively compute union of corresponding parts
    t1->left = unionTreap(t1->left, left);
    t1->right = unionTreap(t1->right, right);

    return t1;
}

// Function to compute the intersection of two treaps
TreapNode* intersect(TreapNode* t1, TreapNode* t2) {
    if (t1 == NULL || t2 == NULL)
        return NULL;

    // If key exists in t2, include it in result
    TreapNode* result = NULL;

    // Split t2 around t1's key to find if it exists
    TreapNode* left = NULL;
    TreapNode* right = NULL;
    TreapNode* equal = NULL;

    // First split: keys < t1->key go to left, keys >= t1->key go to equal_right
    TreapNode* equal_right = NULL;
    split(t2, t1->key - 1, &left, &equal_right);

    // Second split: keys == t1->key go to equal, keys > t1->key go to right
    split(equal_right, t1->key, &equal, &right);

    // If t1->key exists in t2
    if (equal != NULL) {
        // Create a new node for the intersection
        result = createNode(t1->key);

        // Recursively find intersection of left and right subtrees
        result->left = intersect(t1->left, left);
        result->right = intersect(t1->right, right);

        // Clean up
        free(equal); // We created a new node for the result
    } else {
        // Key doesn't exist in t2, just find intersection of subtrees
        result = merge(intersect(t1->left, left), intersect(t1->right, right));
    }

    // Merge back the parts of t2 that we split
    TreapNode* temp = merge(left, equal);
    t2 = merge(temp, right);

    return result;
}

// Function to print the treap in-order (for debugging)
void inorder(TreapNode* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("Key: %d, Priority: %d\n", root->key, root->priority);
        inorder(root->right);
    }
}

// Function to free the memory allocated for the treap
void freeTreap(TreapNode* root) {
    if (root != NULL) {
        freeTreap(root->left);
        freeTreap(root->right);
        free(root);
    }
}

// Main function to demonstrate the treap
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create a treap by inserting elements
    TreapNode* root = NULL;

    printf("--- Insert Operation ---\n");
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Treap after insertions:\n");
    inorder(root);

    printf("\n--- Search Operation ---\n");
    TreapNode* found = search(root, 40);
    if (found != NULL)
        printf("Key 40 found with priority %d\n", found->priority);
    else
        printf("Key 40 not found\n");

    found = search(root, 55);
    if (found != NULL)
        printf("Key 55 found with priority %d\n", found->priority);
    else
        printf("Key 55 not found\n");

    printf("\n--- Erase Operation ---\n");
    root = erase(root, 40);
    printf("Treap after erasing 40:\n");
    inorder(root);

    printf("\n--- Build Operation ---\n");
    int arr[] = {10, 25, 35, 45, 55};
    TreapNode* root2 = build(arr, 5);
    printf("Second treap built from array:\n");
    inorder(root2);

    printf("\n--- Union Operation ---\n");
    TreapNode* unionRoot = unionTreap(root, root2);
    printf("Union of two treaps:\n");
    inorder(unionRoot);

    printf("\n--- Intersection Operation ---\n");
    // Insert some common elements
    root2 = insert(root2, 30);
    root2 = insert(root2, 70);

    printf("Updated second treap:\n");
    inorder(root2);

    // We need to recreate root since it was modified in the union operation
    root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 60);
    root = insert(root, 80);

    TreapNode* intersectRoot = intersect(root, root2);
    printf("\nIntersection of two treaps:\n");
    inorder(intersectRoot);

    // Free allocated memory
    freeTreap(root);
    freeTreap(root2);
    freeTreap(intersectRoot);

    return 0;
}