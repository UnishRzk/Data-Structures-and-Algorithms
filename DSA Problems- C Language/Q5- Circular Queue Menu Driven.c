#include <stdio.h>
#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = -1, rear = -1;

// Function to check if the queue is full
int isFull() {
    return (rear + 1) % MAX_SIZE == front;
}

// Function to check if the queue is empty
int isEmpty() {
    return front == -1;
}

// Function to enqueue (insert) an element
void enqueue(int data) {
    if (isFull()) {
        printf("Queue overflow\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear = (rear + 1) % MAX_SIZE;
    queue[rear] = data;
    printf("Element %d inserted\n", data);
}

// Function to dequeue (remove) an element
int dequeue() {
    if (isEmpty()) {
        printf("Queue underflow\n");
        return -1;
    }
    int data = queue[front];
    if (front == rear) { // only one element in the queue
        front = rear = -1;
    } else {
        front = (front + 1) % MAX_SIZE;
    }
    return data;
}

// Function to display the queue elements
void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (i != rear) {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", queue[rear]);
}

// Main function with menu-driven options
int main() {
    int choice, data;
    while (1) {
        printf("\nCircular Queue Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                data = dequeue();
                if (data != -1)
                    printf("Dequeued element: %d\n", data);
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
