#include <stdio.h>

int main()
{
    int arr[] = {10, 20, 35, 3, 45, 4, 99, 18, 7, 81};
    int n = sizeof(arr) / sizeof(arr[0]);
    int value;
    printf("Enter the element to be verified: ");
    scanf("%d", &value);

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == value)
        {
            printf("the number is at index: %d \n", i);
        }
    }
    printf("The array is: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }
    return 0;
}