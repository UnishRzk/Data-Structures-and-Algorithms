#include <stdio.h>

void shellSort(int arr[], int n) {
    int gap, i, j, temp;
    
    for (gap = n/2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i++) {
            temp = arr[i];
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
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
    
    shellSort(arr, n);
    
    printf("Sorted array:\n");
    printArray(arr, n);
    
    return 0;
}
