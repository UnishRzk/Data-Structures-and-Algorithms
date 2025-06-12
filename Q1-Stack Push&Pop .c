#include <stdio.h>
#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int element) {
    if (top == MAX_SIZE - 1)
        printf("Error: Stack Overflow\n");
    else {
        stack[++top] = element;
        printf("Pushed %d onto the stack.\n", element);
    }
}

int pop() {
    if (top == -1) {
        printf("Error: Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements (top to bottom): ");
    for (int i = top; i >= 0; i--) {  // Print from top to bottom
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int choice, element;
    do {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) { // Validate input
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter element to push: ");
                if (scanf("%d", &element) != 1) {
                    printf("Invalid input! Please enter a number.\n");
                    while (getchar() != '\n'); // Clear input buffer
                    continue;
                }
                push(element);
                break;
            case 2:
                element = pop();
                if (element != -1)
                    printf("Popped element: %d\n", element);
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid Choice! Please enter a number between 1 and 4.\n");
        }
    } while (choice != 4);

    return 0;
}
