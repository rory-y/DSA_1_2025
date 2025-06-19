#include "../headers/heapSort.h"

// To heapify a subtree rooted with node i
// which is an index in arr[].
void heapify(szesszio arr[], int n, int i) {

    // Initialize largest as root
    int largest = i;

    // left index = 2*i + 1
    int l = 2 * i + 1;

    // right index = 2*i + 2
    int r = 2 * i + 2;

    // If left child is larger than root
    if (l < n && arr[l].jegy > arr[largest].jegy) {
        largest = l;
    }

    // If right child is larger than largest so far
    if (r < n && arr[r].jegy > arr[largest].jegy) {
        largest = r;
    }

    // If largest is not root
    if (largest != i) {
        szesszio temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
// Main function to do heap sort
void heapSort(szesszio arr[], int n) {

    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {

        // Move current root to end
        szesszio temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// A utility function to print array of size n
void printArray(szesszio arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s %.2f\n", arr[i].name, arr[i].jegy);
    }
    printf("\n");
}
