//
// Created by rory on 2/17/25.
//

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

/**
 * returns the sum of 3 integer (int) numbers
 * @param input1 first input
 * @param input2 second input
 * @param input3 third input
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
int min(int input1, int input2, int input3);

/**
 * n elemu tomb dinamikus helyfoglalasa
 * @param n a tomb elemeinek szama
 * @return a tomb altal lefoglalt memoria cimet
 */
int* allocateMemoryForArray(int n);

/**
 * n elemu tombnek foglal helyet
 * @param n elemek szama
 * @param dpArray double pointer
 */
void allocateMemoryForArray2(int n, int** dpArray);


void readArray(int* pn, int** dpArray, const char* input);


void printArray(int n, int *pArray, const char *output);


void deallocateMemoryForArray(int **dpArray);

#endif //FUNCTIONS_H
