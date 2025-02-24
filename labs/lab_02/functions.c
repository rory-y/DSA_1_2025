#include "functions.h"

#include <stdio.h>
#include <stdlib.h>


int
sum (int input1, int input2)
{
  return input1 + input2;
}

int
min (int input1, int input2, int input3)
{
  if (input1 < input2 && input1 < input3)
    {
      return input1;
    }
  else if (input2 < input1 && input2 < input3)
    {
      return input2;
    }
  else if (input3 < input1 && input3 < input2)
    {
      return input3;
    }
  else
    return input1;
}


int *
allocateMemoryForArray (int n)
{
  int* p = (int *) malloc (n * sizeof(int));
  if (!p)
    {
      printf ("Error in allocating memory for the array\n");
      return nullptr;
    }
  return p;
}

void
allocateMemoryForArray2 (int n, int **dpArray)
{
  *dpArray = (int*)malloc(n*sizeof(int));
  if (!(*dpArray))
    {
      printf("Memory allocation error");
      exit(-1);
    }
}

void
readArray(int* pn, int** dpArray, const char* input)
{
  if (!freopen(input, "r",stdin))
    {
      exit(-2);
    }
  scanf("%i", pn);
  allocateMemoryForArray2(*pn, dpArray);
  for (int i = 0; i < *pn; i++)
    {
      scanf("%i", &((*dpArray)[i]));
      //scanf("%i",*dpArray+i);
    }
  freopen("CON", "r",stdin);
}

void
printArray(int n, int* pArray, const char* output)
{
  freopen(output, "w",stdout);
  for (int i = 0; i < n; i++)
    {
      printf("%i ", pArray[i]);
      //printf("%i ",*(pArray+i));
    }
  printf("\n");
  freopen("CON", "w",stdout);
}

void deallocateMemoryForArray(int** dpArray)
{
  free(*dpArray);
  *dpArray = NULL;
}