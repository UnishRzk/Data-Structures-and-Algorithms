#include <stdio.h>

#define MAX_SIZE 100

// Function Prototypes
void createList(int list[], int *size);
void insertElement(int list[], int *size, int element, int position);
void modifyElement(int list[], int size, int position, int newValue);
void deleteElement(int list[], int *size, int position);
void traverseList(int list[], int size);
void mergeLists(int list1[], int size1, int list2[], int size2, int mergedList[], int *mergedSize);

int main() {
    int list[MAX_SIZE], list2[MAX_SIZE], mergedList[2 * MAX_SIZE];
    int size = 0, size2 = 0, mergedSize = 0;
    int choice, element, position, newValue;

    do {
        printf("\nList Operations Menu:");
        printf("\n1. Create List");
        printf("\n2. Insert Element");
        printf("\n3. Modify Element");
        printf("\n4. Delete Element");
        printf("\n5. Traverse List");
        printf("\n6. Merge Two Lists");
        printf("\n7. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createList(list, &size);
                break;
            case 2:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                printf("Enter position (1 to %d): ", size + 1);
                scanf("%d", &position);
                insertElement(list, &size, element, position);
                break;
            case 3:
                printf("Enter position to modify (1 to %d): ", size);
                scanf("%d", &position);
                printf("Enter new value: ");
                scanf("%d", &newValue);
                modifyElement(list, size, position, newValue);
                break;
            case 4:
                printf("Enter position to delete (1 to %d): ", size);
                scanf("%d", &position);
                deleteElement(list, &size, position);
                break;
            case 5:
                traverseList(list, size);
                break;
            case 6:
                printf("Creating second list:\n");
                createList(list2, &size2);
                mergeLists(list, size, list2, size2, mergedList, &mergedSize);
                printf("Merged List: ");
                traverseList(mergedList, mergedSize);
                break;
            case 7:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}

// Function to create a list
void createList(int list[], int *size) {
    printf("Enter number of elements: ");
    scanf("%d", size);

    if (*size > MAX_SIZE) {
        printf("Size exceeds maximum limit!\n");
        *size = 0;
        return;
    }

    printf("Enter %d elements: ", *size);
    for (int i = 0; i < *size; i++) {
        scanf("%d", &list[i]);
    }
}

// Function to insert an element
void insertElement(int list[], int *size, int element, int position) {
    if (*size >= MAX_SIZE) {
        printf("List is full!\n");
        return;
    }

    if (position < 1 || position > *size + 1) {
        printf("Invalid position!\n");
        return;
    }

    for (int i = *size; i >= position; i--) {
        list[i] = list[i - 1];
    }

    list[position - 1] = element;
    (*size)++;
    printf("Element inserted successfully!\n");
}

// Function to modify an element
void modifyElement(int list[], int size, int position, int newValue) {
    if (position < 1 || position > size) {
        printf("Invalid position!\n");
        return;
    }

    list[position - 1] = newValue;
    printf("Element modified successfully!\n");
}

// Function to delete an element
void deleteElement(int list[], int *size, int position) {
    if (position < 1 || position > *size) {
        printf("Invalid position!\n");
        return;
    }

    for (int i = position - 1; i < *size - 1; i++) {
        list[i] = list[i + 1];
    }

    (*size)--;
    printf("Element deleted successfully!\n");
}

// Function to traverse the list
void traverseList(int list[], int size) {
    if (size == 0) {
        printf("List is empty!\n");
        return;
    }

    printf("List elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
}

// Function to merge two lists
void mergeLists(int list1[], int size1, int list2[], int size2, int mergedList[], int *mergedSize) {
    *mergedSize = size1 + size2;

    for (int i = 0; i < size1; i++) {
        mergedList[i] = list1[i];
    }

    for (int i = 0; i < size2; i++) {
        mergedList[size1 + i] = list2[i];
    }

    printf("Lists merged successfully!\n");
}
