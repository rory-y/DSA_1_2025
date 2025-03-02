#include "functions.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int
sum (int input1, int input2)
{
  return input1 + input2;
}

float
min (float input1, float input2, float input3)
{
    float min = input1;
    if(input2 < min)
      min = input2;
    if(input3 < min)
      min = input3;
    return min;
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
allocateMemoryFor2DCharArray2(int row, int col, char ***dpArray)
{
  *dpArray = (char**) malloc (row * sizeof(char*));
  if (!(*dpArray))
    {
      printf("Memory allocation error 1");
      exit(-1);
    }
  for (int i = 0; i < row; i++)
    {
      (*dpArray)[i] = (char*)malloc (col * sizeof(char));
      if(!((*dpArray)[i]))
        {
          printf("Memory allocation error 2");
          exit(-1);
        }
    }
}

void
deallocateMemoryFor2DCharArray(int rows, char **tpArray)
{
  if (tpArray == NULL)
    {
      return;
    }

  for (int i = 0; i < rows; i++)
    {
      free(tpArray[i]);
    }
  free(tpArray);
}


void
allocateMemoryForFloatArray2 (int n, float **dpArray)
{
  *dpArray = (float*)malloc(n*sizeof(float));
  if (!(*dpArray))
    {
      printf("Memory allocation error");
      exit(-1);
    }
}

void
readArray(int* pn, int** dpArray, const char* input)
{
  if (!freopen(input, "r", stdin))
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
  freopen("CON", "r", stdin);
}

void
read2DCharArray (int* pRows, int *pCols, char** tpArray, const char* input)
{
  FILE *pfile = fopen(input, "r");
  if (!pfile)
    {
      perror("File opening error");
      exit(-1);
    }

//  char trash[4];
//  fgets(trash, 4, pfile);
  while(fgetc(pfile) != '\n'); // skips the first line of the input file
  for (int i = 0; i < *pRows; i++)
    {
      for (int j = 0; j < *pCols; j++)
        {
          fscanf(pfile, " %c", &tpArray[i][j]);
        }
    }

  fclose(pfile);
}

void
print2DCharArray(int rows, int cols, char** dpArray)
{
  for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < cols; j++)
        {
          printf("%4c", dpArray[i][j]);
        }
      printf("\n");
    }
}

void
printArray(int n, int* pArray, const char* output)
{
  FILE *pfile = fopen(output, "w");
  if (!pfile)
    {
      printf("Error in opening file");
      exit(-1);
    }
  for (int i = 0; i < n; i++)
    {
      fprintf(pfile, "%d\n", pArray[i]);
    }
  fprintf(pfile, "\n");
  fclose(pfile);
//  freopen(output, "w", stdout);
//  for (int i = 0; i < n; i++)
//    {
//      printf("%d ", pArray[i]);
//      //printf("%i ",*(pArray+i));
//    }
//  printf("\n");
//  freopen("CON", "w", stdout);
}

void
printFloatArray(int n, float* pArray, const char* output)
{
  FILE *pfile = fopen(output, "w");
  if (!pfile)
    {
      printf("Error in opening file");
      exit(-1);
    }
  for (int i = 0; i < n; i++)
    {
      fprintf(pfile, "%f ", pArray[i]);
    }
  fprintf(pfile, "\n");
  fclose(pfile);
//  freopen(output, "w",stdout);
//  for (int i = 0; i < n; i++)
//    {
//      printf("%f ", pArray[i]);
//    }
//  printf("\n");
//  freopen("CON", "w", stdout);
}

void deallocateMemoryForIntArray(int** dpArray)
{
  free(*dpArray);
  *dpArray = NULL;
}

void deallocateMemoryForFloatArray(float** dpArray)
{
  free(*dpArray);
  *dpArray = NULL;
}

float
randomFloat(float min, float max)
{
  //srand((unsigned int)time(NULL));
  float scale = rand() / (float) RAND_MAX; // [0, 1.0]
  return min + scale * ( max - min );      // [min, max]
}


void
fillWithRandomFloats(int n, float *pArray, float min, float max)
{
  srand(time(NULL));
  for(int i = 0; i < n; i++)
    {
      pArray[i] = randomFloat(min, max);
    }
}