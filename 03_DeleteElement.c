#include <stdio.h>

void deleteElement(int arr[], int *n, int element)
{
    int i;
    for (i = 0; i < *n; i++)
    {
        if (arr[i] == element)
        {
            break;
        }
    }

    if (i < *n)
    {
        for (int j = i; j < *n - 1; j++)
        {
            arr[j] = arr[j + 1];
        }
        (*n)--;
    }
    else
    {
        printf("Element not found in the array\n");
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    int element;

    printf("Original array: ");
    printArray(arr, n);

    printf("Enter the element to be deleted: ");
    scanf("%d", &element);

    deleteElement(arr, &n, element);

    printf("Array after deletion: ");
    printArray(arr, n);

    return 0;
}
