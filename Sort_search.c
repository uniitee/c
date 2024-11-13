#include <stdio.h>

// time complexity: O(n^2)
void BubbleSort(int arr[], int n){
    int temp;
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if (arr[j] > arr[j+1]){
                temp = arr[j]; 
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// time complexity: O(n^2)
void selectionSort(int arr[], int n){
    int temp, min;
    for(int i = 0; i < n-1; i++){
        min = i;
        for(int j = i+1; j < n-1; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

// time complexity: O(n^2)
void merge(int arr[], int lb, int mid, int ub){
    int i = lb, j = mid+1, k = lb, temp[100];
    while(i <= mid && j <= ub){
        if(arr[i] < arr[j]){
            temp[k] = arr[i];
            i++;
        }
        else{
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    if(i > mid){
        while(j <= ub){
            temp[k] = arr[j];
            j++;
            k++;
        }
    }
    else{
        while(i <= mid){
            temp[k] = arr[i];
            i++;
            k++;
        }
    }
    for(int i = lb; i <= ub; i++){
        arr[i] = temp[i];
    }
}
// time complexity: O(nlogn)
void mergeSort(int arr[], int lb, int ub){
    if(lb < ub){
        int mid = (lb+ub)/2;
        mergeSort(arr, lb, mid);
        mergeSort(arr, mid+1, ub);
        merge(arr, lb, mid, ub);
    }
}

// // time complexity: O(nlogn)
// void heapify(int arr[], int n, int i){
//     int largest = i;
//     int l = 2*i + 1;
//     int r = 2*i + 2;
//     if(l < n && arr[l] > arr[largest]){
//         largest = l;
//     }
//     if(r < n && arr[r] > arr[largest]){
//         largest = r;
//     }
//     if(largest != i){
//         int temp = arr[i];
//         arr[i] = arr[largest];
//         arr[largest] = temp;
//         heapify(arr, n, largest);
//     }
// }
// // time complexity: O(nlogn)
// void heapSort(int arr[], int n){
//     for(int i = n/2-1; i >= 0; i--){
//         heapify(arr, n, i);
//     }
//     for(int i = n-1; i >= 0; i--){
//         int temp = arr[0];
//         arr[0] = arr[i];
//         arr[i] = temp;
//         heapify(arr, i, 0);
//     }
// }

// time complexity: O(n)
int partition(int arr[], int lb, int ub){
    int pivot = arr[lb];
    int start = lb;
    int end = ub;
    while(start < end){
        while(arr[start] <= pivot){
            start++;
        }
        while(arr[end] > pivot){
            end--;
        }
        if(start < end){
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }
    }
    int temp = arr[lb];
    arr[lb] = arr[end];
    arr[end] = temp;
    return end;
}
// time complexity: O(nlogn)
void quickSort(int arr[], int lb, int ub){
    if(lb < ub){
        int loc = partition(arr, lb, ub);
        quickSort(arr, lb, loc-1);
        quickSort(arr, loc+1, ub);
    }
}

// time complexity: O(n)
int hashSearch(int arr[], int n, int val){
    int hashTable[100] = {0};
    for(int i = 0; i < n; i++){
        hashTable[arr[i]] = 1;
    }
    if(hashTable[val] == 1){
        return 1;
    }
    return 0;
}

// time complexity: O(n)
int linearSearch(int arr[], int n, int val)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == val)
        {
            return i;
        }
    }
    return -1;
}

// time complexity: O(logn)
int binarySearch(int arr[], int n, int val)
{
    int lb = 0, ub = n-1, mid;
    while (lb <= ub){
        mid = (lb+ub)/2;
        if(arr[mid] == val){
            return mid;
        }
        else if(arr[mid] < val){
            lb = mid + 1;
        }
        else{
            ub = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {10, 20, 35, 3, 45, 4, 99, 18, 7, 81};
    int n = sizeof(arr) / sizeof(arr[0]);
    int val;
    printf("Enter the element to be verified: ");
    scanf("%d", &val);
    printf("choose the sort algorithm: \n");
    printf(" 1. Bubble Sort\n 2. Selection Sort\n 3. Merge Sort\n 4. Quick Sort\n");
    int choice;
    scanf("%d", &choice);
    switch(choice){
        case 1:
            BubbleSort(arr, n);
            break;
        case 2:
            selectionSort(arr, n);
            break;
        case 3:
            mergeSort(arr, 0, n-1);
            break;
        case 4:
            quickSort(arr, 0, n-1);
            break;
        default:
            printf("Invalid choice\n");
            break;
    }
    printf("The array is: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");

    printf("Choose the search algorithm: \n");
    printf(" 1. Linear Search\n 2. Binary Search\n 3. Hash Search\n");
    scanf("%d", &choice);
    switch(choice){
        case 1:
            if (linearSearch(arr, n, val) != -1)
            {
                printf("The number is at index: %d \n", linearSearch(arr, n, val));
            }
            else
            {
                printf("The number is not in the array\n");
            }
            break;
        case 2:
            if (binarySearch(arr, n, val) != -1)
            {
                printf("The number is at index: %d \n", binarySearch(arr, n, val));
            }
            else
            {
                printf("The number is not in the array\n");
            }
            break;
        case 3:
            if (hashSearch(arr, n, val) == 1)
            {
                printf("The number is in the array\n");
            }
            else
            {
                printf("The number is not in the array\n");
            }
            break;
        default:
            printf("Invalid choice\n");
            break;
    }

}
