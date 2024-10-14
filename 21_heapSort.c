#include <stdio.h>
// Function to swap two elements
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
// Function to heapify a subtree rooted with node i
void heapify(int arr[], int n, int i){
    int largest = i;       // Initialize largest as root
    int left = 2 * i + 1;  // left child index
    int right = 2 * i + 2; // right child index
    // If left child is larger than root
    if (left < n && arr[left] > arr[largest]){
        largest = left;
    }
    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest]){
        largest = right;
    }
    // If largest is not root
    if (largest != i){
        swap(&arr[i], &arr[largest]); // Swap root and largest
        // Recursively heapify the affected subtree
        heapify(arr, n, largest);
    }
}
// Function to perform Heap Sort
void heapSort(int arr[], int n){
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--){
        heapify(arr, n, i);
    }
    // One by one extract elements from heap
    for (int i = n - 1; i > 0; i--){
        swap(&arr[0], &arr[i]); // Move current root to end
        heapify(arr, i, 0);     // call max heapify on the reduced heap
    }
}
// Function to print the array
void printArray(int arr[], int n){
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
// Main function
int main(){
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Unsorted array: ");
    printArray(arr, n);
    heapSort(arr, n);
    printf("Sorted array using Heap Sort: ");
    printArray(arr, n);
    return 0;
}