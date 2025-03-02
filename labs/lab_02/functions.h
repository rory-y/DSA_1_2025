//
// Created by rory on 2/17/25.
//

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

/**
 * returns the sum of 3 integer (int) numbers
 * @param input1 first input
 * @param input2 second input
 * @return the sum of the 3 inputs
 */
int sum(int input1, int input2);

/**
 * meow meow yippieee
 * @param input1 first input
 * @param input2 second input
 * @param input3 third input
 * @return the smallest value out of the 3 inputs
 */
float min(float input1, float input2, float input3);

/**
 * n elemu tomb dinamikus helyfoglalasa
 * @param n a tomb elemeinek szama
 * @return a tomb altal lefoglalt memoria cimet
 */
int* allocateMemoryForArray(int n);

/**
 * n elemu tombnek foglal helyet
 * @param n elemek szama
 * @param dpArray double pointer (you need a normal pointer?)
 */
void allocateMemoryForArray2(int n, int** dpArray);

/**
 *
 * @param n number of elements in the array
 * @param dpArray double pointer to the array pointer (use &array_pointer_name)
 */
void allocateMemoryForFloatArray2 (int n, float **dpArray);

/**
 *
 * @param row number of rows
 * @param col number of columns
 * @param dpArray triple array pointer (***tpArray)
 */
void allocateMemoryFor2DCharArray2 (int row, int col, char ***dpArray);

/**
 * 
 * @param rows number of rows
 * @param tpArray triple array pointer (***tpArray)
 */
void deallocateMemoryFor2DCharArray (int rows, char** tpArray);


void readArray(int* pn, int** dpArray, const char* input);


/**
 * populates a 2D char array from a file
 * @param rows number of rows in the matrix
 * @param cols number of cols in the matrix
 * @param tpArray triple array pointer (ex. ***tpArray)
 * @param input input filname (ex. "input.txt")
 */
void read2DCharArray (int* rows, int* cols, char** tpArray, const char* input);

/**
 * prints a char matrix to the console
 * @param rows number of rows in the matrix
 * @param cols number of cols in the matrix
 * @param dpArray double array pointer (ex. **tpArray)
 */
void print2DCharArray (int rows, int cols, char** dpArray);


void printArray(int n, int *pArray, const char *output);

/**
 * prints the contents of a float array to the specified location
 * @param n number of elements in the array
 * @param pArray array pointer
 * @param output output destination (ex. "CON" or "output.txt")
 */
void printFloatArray(int n, float *pArray, const char *output);


void deallocateMemoryForIntArray(int **dpArray);


void deallocateMemoryForFloatArray(float **dpArray);

/**
 * populates a float array with random float numbers
 * @param n number of elements in the array
 * @param pArray array pointer (&array)
 * @param min minimum value
 * @param max maximum value
 */
void fillWithRandomFloats(int n, float *pArray, float min, float max);


/**
 * random float number generator
 * @param min minimum value
 * @param max maximum value
 * @return - a random floating point number from [min, max]
 */
float randomFloat(float min, float max);

/**
 * 
 * @param rows number of rows
 * @param columnIndex 
 * @param pMatrix 
 * @return 
 */
char minimumValueOfColumn(int rows, int columnIndex, char **pMatrix);

#endif //FUNCTIONS_H
