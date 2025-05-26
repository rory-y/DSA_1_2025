#include "headers/heapSort.h"

int
main ()
{
  int arr[] = { 9, 4, 3, 8, 10, 2, 5 };
  int n = sizeof (arr) / sizeof (arr[0]);

  heapSort (arr, n);

  printf ("Sorted array is \n");
  printArray (arr, n);
  return 0;
}
