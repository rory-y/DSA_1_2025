#include "headers/main.h"
#include "headers/treap.h"

// main function to demonstrate the treap
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Create a treap by inserting elements
  TreapNode *root = NULL;

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
  TreapNode *found = search(root, 40);
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
  TreapNode *root2 = build(arr, 5);
  printf("Second treap built from array:\n");
  inorder(root2);

  printf("\n--- Union Operation ---\n");
  TreapNode *unionRoot = unionTreap(root, root2);
  printf("Union of two treaps:\n");
  inorder(unionRoot);

  printf("\n--- Intersection Operation ---\n");
  // insert some common elements
  root2 = insert(root2, 30);
  root2 = insert(root2, 70);

  printf("Updated second treap:\n");
  inorder(root2);

  // we need to recreate root since it was modified in the union operation
  root = NULL;
  root = insert(root, 50);
  root = insert(root, 30);
  root = insert(root, 70);
  root = insert(root, 20);
  root = insert(root, 60);
  root = insert(root, 80);

  TreapNode *intersectRoot = intersect(root, root2);
  printf("\nIntersection of two treaps:\n");
  inorder(intersectRoot);

  // free allocated memory
  freeTreap(root);
  freeTreap(root2);
  freeTreap(intersectRoot);

  return 0;
}
