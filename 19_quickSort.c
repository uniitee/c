#include <stdio.h>
// Function to perform Insertion Sort
void insertionSort(int arr[], int n){
    for (int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;
        // Move elements of arr[0..i-1] that are greater than key to one position ahead of their current position
        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
// Function to perform Quick Sort
void quickSort(int arr[], int low, int high){
    if (low < high){
        // Partitioning index
        int pivot = arr[high]; // Choose the rightmost element as pivot
        int i = (low - 1);     // Index of smaller element
        for (int j = low; j < high; j++){
            // If current element is smaller than or equal to pivot
            if (arr[j] <= pivot){
                i++;
                // Swap arr[i] and arr[j]
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        // Swap arr[i + 1] and arr[high] (or pivot)
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        // Recursively sort elements before and after partition
        quickSort(arr, low, i);
        quickSort(arr, i + 2, high);
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
    int choice;
    printf("Unsorted array: ");
    printArray(arr, n);
    printf("Choose sorting algorithm:\n");
    printf("1. Insertion Sort\n");
    printf("2. Quick Sort\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);
    // Make a copy of the original array for each sort
    int arrInsertion[n], arrQuick[n];
    for (int i = 0; i < n; i++){
        arrInsertion[i] = arr[i];
        arrQuick[i] = arr[i];
    }
    switch (choice){
    case 1:
        insertionSort(arrInsertion, n);
        printf("Sorted array using Insertion Sort: ");
        printArray(arrInsertion, n);
        break;
    case 2:
        quickSort(arrQuick, 0, n - 1);
        printf("Sorted array using Quick Sort: ");
        printArray(arrQuick, n);
        break;
    default:
        printf("Invalid choice!\n");
        break;
    }
    return 0;
}