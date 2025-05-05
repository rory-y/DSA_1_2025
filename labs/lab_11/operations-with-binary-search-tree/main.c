#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "headers/binary_search_tree.h"

int main() {
// srand(time(nullptr));
//   // creating the root
//   int x = 500 + rand() % 401;
//   Node *root = createNewNode(x);
//   // filling up the tree
//   for (int i = 0; i < 10; i++)
//     {
//       int y = 500 + rand() % 401;
//       insert(root, y);
//     }
//     insert(root, x);
//   // inorder traversals
//     printf("\nInorder: ");
//     inorderTraversal(root);
//
//     destroyBinaryTree(&root);
  freopen("data.txt", "r", stdin);
  Friend uj;
  Node *head=nullptr;
  while ((scanf("%[^;];%d;%d;%d;%c;%d\n",
      uj.nev,
      &uj.szuletesiDatum.ev,
      &uj.szuletesiDatum.honap,
      &uj.szuletesiDatum.nap,
      &uj.nem,
      &uj.bulizas) != EOF))
     {
       if(head==NULL) {
           head = createNewNode(uj);
       }
       else
         {
           insert(head, uj);
         }
     }
  inorderTraversal(head);
  return 0;
}