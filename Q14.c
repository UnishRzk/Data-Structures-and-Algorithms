#include <stdio.h>

int main() {
    int n, key, low = 0, high, mid, arr[100];

    printf("Enter number of elements: ");
    scanf("%d", &n);
    high = n - 1;

    printf("Enter %d sorted elements: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    printf("Enter element to search: ");
    scanf("%d", &key);

    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == key) return printf("Element found at index %d\n", mid), 0;
        (arr[mid] < key) ? (low = mid + 1) : (high = mid - 1);
    }

    printf("Element not found\n");
    return 0;
}
