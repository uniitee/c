// Write a programe to merge two given sorted arrays into a single sorted array.

#include <stdio.h>

int mergeArrays(int arr1[], int arr2[], int n1, int n2, int arr3[])
{
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
        {
            arr3[k++] = arr1[i++];
        }
        else
        {
            arr3[k++] = arr2[j++];
        }
    }
    while (i < n1)
    {
        arr3[k++] = arr1[i++];
    }
    while (j < n2)
    {
        arr3[k++] = arr2[j++];
    }
    return k;
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int arr1[] = {1, 3, 6, 7};
    int arr2[] = {2, 3, 5, 8};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int arr3[n1 + n2];
    int n3 = mergeArrays(arr1, arr2, n1, n2, arr3);
    printf("Array 1: ");
    printArray(arr1, n1);
    printf("\nArray 2: ");
    printArray(arr2, n2);
    printf("\nArray after merging: ");
    printArray(arr3, n3);
    return 0;
}