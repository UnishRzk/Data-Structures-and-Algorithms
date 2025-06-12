#include <stdio.h>

// Binary Search to find the position to insert
int binarySearch(int arr[], int item, int low, int high) {
    if (high <= low)
        return (item > arr[low]) ? (low + 1) : low;
    
    int mid = (low + high) / 2;
    
    if (item == arr[mid])
        return mid + 1;
    
    if (item > arr[mid])
        return binarySearch(arr, item, mid + 1, high);
    
    return binarySearch(arr, item, low, mid - 1);
}

void binarySort(int arr[], int n) {
    int i, loc, j, k, selected;
    
    for (i = 1; i < n; ++i) {
        j = i - 1;
        selected = arr[i];
        
        // Find location where selected should be inserted
        loc = binarySearch(arr, selected, 0, j);
        
        // Move all elements after location to one step right
        while (j >= loc) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = selected;
    }
}

void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

int main() {
    int arr[100], n, i;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    binarySort(arr, n);
    
    printf("Sorted array:\n");
    printArray(arr, n);
    
    return 0;
}
