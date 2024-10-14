#include <stdio.h>
// Function to perform Bubble Sort
void bubbleSort(int arr[], int n){
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j + 1]){
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
// Function to perform Selection Sort
void selectionSort(int arr[], int n){
    for (int i = 0; i < n - 1; i++){
        int minIndex = i;
        for (int j = i + 1; j < n; j++){
            if (arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        // Swap the found minimum element with the first element
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
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
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);
    // Make a copy of the original array for each sort
    int arrBubble[n], arrSelection[n];
    for (int i = 0; i < n; i++){
        arrBubble[i] = arr[i];
        arrSelection[i] = arr[i];
    }
    switch (choice){
    case 1:
        bubbleSort(arrBubble, n);
        printf("Sorted array using Bubble Sort: ");
        printArray(arrBubble, n);
        break;
    case 2:
        selectionSort(arrSelection, n);
        printf("Sorted array using Selection Sort: ");
        printArray(arrSelection, n);
        break;
    default:
        printf("Invalid choice!\n");
        break;
    }
    return 0;
}