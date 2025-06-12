#include <stdio.h>

int main() {
    int n, key, i, arr[100];  

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) scanf("%d", &arr[i]);

    printf("Enter element to search: ");
    scanf("%d", &key);

    for (i = 0; i < n && arr[i] != key; i++); 

    printf(arr[i] == key ? "Element found at index %d\n" : "Element not found\n", i);
    return 0;
}
