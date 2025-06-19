#include "main.h"

typedef struct szesszio {
        char name[16];
        float jegy;
} szesszio;

/**
 * @arr
 * @n
 * @i
 */
void heapify(szesszio arr[], int n, int i);

/**
 * @arr
 * @n
 */
void heapSort(szesszio arr[], int n);

/**
 * @arr
 * @n
 */
void printArray(szesszio arr[], int n);
