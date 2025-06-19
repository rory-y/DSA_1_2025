#include "headers/heapSort.h"
#include <stdlib.h>

int main() {
    szesszio *atlagok = (szesszio *)malloc(CAPACITY * sizeof(szesszio));
    if (!atlagok) {
        printf("failed to allocate memory for the array\n");
        return (-1);
    }

    if (!freopen("../inputs/szesszio.csv", "r", stdin)) {
        printf("couldn't open file");
        return -1;
    }

    int i = 0;
    while (scanf("%[^,],%f\n", atlagok[i].name, &atlagok[i].jegy) != EOF) {
        printf("%s %.2f\n", atlagok[i].name, atlagok[i].jegy);
        i++;
    }
    int n = i;

    heapify(atlagok, n, i);
    heapSort(atlagok, n);
    printf("-------------------------------\n");
    printArray(atlagok, n);
    return 0;
}
