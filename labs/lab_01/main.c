#include "functions.h"
#include <stdio.h>

int main(void) {
    printf("meow :3\n");
    int n = 5, *array;
    readArray(n, &array, "../in-output/input.txt");
    printArray(n, array, "../in-output/output.txt");
    deallocateMemoryForArray(&array);

    return 0;
}
