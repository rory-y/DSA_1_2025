#include <stdio.h>
#include "functions.h"

int main(void) {
    printf("meow :3\n");
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    printf("%d\n", sum(a, b, c));
    printf("%d\n", min(a, b, c));
    allocateMemoryForArray (9);
    int* array;
    allocateMemoryForArray2 (9,&array);

    return 0;
}
