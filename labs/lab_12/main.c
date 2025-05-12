#include "headers/main.h"
#include "headers/binary_tree.h"

int main(void)
{
  /* MENU IMPLEMENTATION */
  printf("Please choose an option\n"
         "-> add new book (1)\n"
         "-> take book out (2)\n"
         "-> take book back (3)\n"
         "-> list all books in library (4)\n"
         "-> list old books (5)\n");
  int userInput;

  Node *root = createNewNode (readOneBookFromFile (pfile));

  scanf("%d", userInput);
  switch (userInput)
    {
    case 1:
      FILE *pfile = fopen("../inputs/books.txt", "r");
      if (!pfile)
      {
        perror("Error in opening file\n");
        return -1;
      }
      else
      {
        printf("File read successfully\n");
      }
      Book_t tempBook = readOneBookFromFile (pfile);
    break;
    default:
    break;
    }


  /* READING FROM THE FILE TO THE TREE */
  // open the file for reading
  //
  // Node *root = createNewNode (readOneBookFromFile (pfile));
  // while (!feof(pfile))
  //   {
  //     Book_t temp = readOneBookFromFile (pfile);
  //     if (temp.inLibrary)
  //       {
  //         insertLeft (root, temp);
  //       }
  //     else
  //       {
  //         insertRight (root, temp);
  //       }
  //   }
  //
  // /* PRINTING OUT THE TREE */
  // postorderTraversal(root);
  //
  // destroyBinaryTree (&root);
  // fclose(pfile);
  return 0;
}
