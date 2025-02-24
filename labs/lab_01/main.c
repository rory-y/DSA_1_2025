#include <stdio.h>
#include "functions.h"

int main(void) {
  printf("meow :3\n");
  int n, *array;
  readArray(&n, &array, "input.txt");
  printArray (n, array, "CON");


    return 0;
}
