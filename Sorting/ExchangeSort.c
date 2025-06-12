#include <stdio.h>

void exchangeSort(int arr[], int n) {
    int i, j, temp;
    
    for (i = 0; i < n-1; i++) {
        for (j = i+1; j < n; j++) {
            if (arr[i] > arr[j]) {
                // Swap arr[i] and arr[j]
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
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
    
    exchangeSort(arr, n);
    
    printf("Sorted array:\n");
    printArray(arr, n);
    
    return 0;
}
