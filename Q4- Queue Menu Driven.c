#include <stdio.h>
#define MAX 100

int stack1[MAX], stack2[MAX];
int top1 = -1, top2 = -1;

// Push element onto stack1
void push1(int x) {
    if (top1 == MAX - 1) {
        printf("Stack1 Overflow\n");
        return;
    }
    stack1[++top1] = x;
}

// Pop element from stack1
int pop1() {
    if (top1 == -1)
        return -1;
    return stack1[top1--];
}

// Push element onto stack2
void push2(int x) {
    if (top2 == MAX - 1) {
        printf("Stack2 Overflow\n");
        return;
    }
    stack2[++top2] = x;
}

// Pop element from stack2
int pop2() {
    if (top2 == -1)
        return -1;
    return stack2[top2--];
}

// Enqueue operation: simply push the element into stack1
void enqueue(int x) {
    push1(x);
    printf("Enqueued %d\n", x);
}

// Dequeue operation:
// If stack2 is empty, move all elements from stack1 to stack2, then pop from stack2.
int dequeue() {
    int x;
    if (top2 == -1) {
        if (top1 == -1) {
            printf("Queue is empty.\n");
            return -1;
        }
        while (top1 != -1) {
            x = pop1();
            push2(x);
        }
    }
    x = pop2();
    return x;
}

// Display the current queue elements in order
void displayQueue() {
    int i;
    if (top1 == -1 && top2 == -1) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    // Print elements from stack2 (which are in correct order for the front part)
    for (i = top2; i >= 0; i--)
        printf("%d ", stack2[i]);
    // Print elements from stack1 in order (bottom to top)
    for (i = 0; i <= top1; i++)
        printf("%d ", stack1[i]);
    printf("\n");
}

int main() {
    int choice, value, x;
    
    do {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                x = dequeue();
                if (x != -1)
                    printf("Dequeued element: %d\n", x);
                break;
            case 3:
                displayQueue();
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while(choice != 4);
    
    return 0;
}
